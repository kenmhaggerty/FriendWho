//
//  FWFacebookManager.m
//  FriendWho
//
//  Created by Ken M. Haggerty on 2/29/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES (Private) //

#pragma mark - // IMPORTS (Private) //

#import "FWFacebookManager.h"
#import "AKDebugger.h"
#import <FBSDKCoreKit/FBSDKCoreKit.h>
#import "FWPrivateInfo.h"

#pragma mark - // DEFINITIONS (Private) //

NSString * const FacebookAPIPermissionPublicProfile = @"public_profile";
NSString * const FacebookAPIPermissionFriends = @"user_friends";
NSString * const FacebookAPIPermissionEmail = @"email";
NSString * const FacebookAPIPermissionAboutMe = @"user_about_me";
NSString * const FacebookAPIPermissionBooks = @"user_actions.books";
NSString * const FacebookAPIPermissionFitness = @"user_actions.fitness";
NSString * const FacebookAPIPermissionMusic = @"user_actions.music";
NSString * const FacebookAPIPermissionNews = @"user_actions.news";
NSString * const FacebookAPIPermissionWatchedVideos = @"user_actions.video";
NSString * const FacebookAPIPermissionBirthday = @"user_birthday";
NSString * const FacebookAPIPermissionEducation = @"user_education_history";
NSString * const FacebookAPIPermissionEvents = @"user_events";
NSString * const FacebookAPIPermissionGamesActivity = @"user_games_activity";
NSString * const FacebookAPIPermissionHometown = @"user_hometown";
NSString * const FacebookAPIPermissionLikes = @"user_likes";
NSString * const FacebookAPIPermissionLocation = @"user_location";
NSString * const FacebookAPIPermissionManagedGroups = @"user_managed_groups";
NSString * const FacebookAPIPermissionPhotos = @"user_photos";
NSString * const FacebookAPIPermissionPosts = @"user_posts";
NSString * const FacebookAPIPermissionRelationships = @"user_relationships";
NSString * const FacebookAPIPermissionRelationshipDetails = @"user_relationship_details";
NSString * const FacebookAPIPermissionReligionAndPolitics = @"user_religion_politics";
NSString * const FacebookAPIPermissionTaggedPlaces = @"user_tagged_places";
NSString * const FacebookAPIPermissionVideos = @"user_videos";
NSString * const FacebookAPIPermissionWebsite = @"user_website";
NSString * const FacebookAPIPermissionEmployment = @"user_work_history";

NSString * const FacebookAPIUserKeyID = @"id";
NSString * const FacebookAPIUserKeyName = @"name";

NSString * const FacebookAPIGraphRequestKey = @"fields";
NSString * const FacebookAPINotificationKeyNewProfile = @"FBSDKProfileNew";

@interface FWFacebookManager ()
@property (nonatomic, strong) NSDictionary *currentUser;
@property (nonatomic, strong) FBSDKProfile *currentProfile;

// GENERAL //

+ (instancetype)sharedManager;
+ (void)checkForAccessTokenWithSuccess:(void (^)(void))successBlock failure:(void (^)(void))failureBlock;

// RESPONDERS //

- (void)currentUserDidChange:(NSNotification *)notification;
- (void)profileDidChange:(NSNotification *)notification;

@end

@implementation FWFacebookManager

#pragma mark - // SETTERS AND GETTERS //

#pragma mark - // INITS AND LOADS //

- (void)dealloc {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_ACCOUNTS] message:nil];
    
    [self teardown];
}

- (id)init {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_ACCOUNTS] message:nil];
    
    self = [super init];
    if (self) {
        [self setup];
    }
    
    return self;
}

- (void)awakeFromNib {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_ACCOUNTS] message:nil];
    
    [super awakeFromNib];
    
    [self setup];
}

#pragma mark - // PUBLIC METHODS (Setup) //

+ (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_FACEBOOK] message:nil];
    
    [[FBSDKApplicationDelegate sharedInstance] application:application didFinishLaunchingWithOptions:launchOptions];
}

+ (void)applicationDidBecomeActive {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_FACEBOOK] message:nil];
    
    [FBSDKAppEvents activateApp];
}

+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_FACEBOOK] message:nil];
    
    return [[FBSDKApplicationDelegate sharedInstance] application:application openURL:url sourceApplication:sourceApplication annotation:annotation];
    
//    return [FBAppCall handleOpenURL:url sourceApplication:sourceApplication];
}

#pragma mark - // PUBLIC METHODS (Getter) //

+ (NSArray *)permissions {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeGetter tags:@[AKD_FACEBOOK] message:nil];
    
    return @[FacebookAPIPermissionPublicProfile, FacebookAPIPermissionFriends, FacebookAPIPermissionAboutMe, FacebookAPIPermissionBooks, FacebookAPIPermissionFitness, FacebookAPIPermissionMusic, FacebookAPIPermissionNews, FacebookAPIPermissionWatchedVideos, FacebookAPIPermissionBirthday, FacebookAPIPermissionEducation, FacebookAPIPermissionEvents, FacebookAPIPermissionHometown, FacebookAPIPermissionLikes, FacebookAPIPermissionPhotos, FacebookAPIPermissionPosts, FacebookAPIPermissionRelationships, FacebookAPIPermissionRelationshipDetails, FacebookAPIPermissionReligionAndPolitics, FacebookAPIPermissionTaggedPlaces, FacebookAPIPermissionVideos, FacebookAPIPermissionEmployment];
}

+ (NSDictionary *)currentUser {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeGetter tags:@[AKD_ACCOUNTS, AKD_DATA] message:nil];
    
    return [FWFacebookManager sharedManager].currentUser;
}

+ (void)fetchCurrentProfileWithCompletion:(void (^)(NSDictionary *))completionBlock {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeGetter tags:@[AKD_ACCOUNTS] message:nil];
    
    FWFacebookManager *sharedManager = [FWFacebookManager sharedManager];
    NSDictionary *currentUser = sharedManager.currentUser;
    if (currentUser) {
        completionBlock(currentUser);
        return;
    }
    
    [FWFacebookManager checkForAccessTokenWithSuccess:^{
        
        NSArray *parameters = @[@"id", @"first_name", @"last_name", @"hometown", @"name", @"education", @"likes", @"permissions", @"friends"];
        [[[FBSDKGraphRequest alloc] initWithGraphPath:@"me" parameters:@{FacebookAPIGraphRequestKey : [parameters componentsJoinedByString:@", "]}] startWithCompletionHandler:^(FBSDKGraphRequestConnection *connection, id result, NSError *error) {
            
            if (error) {
                [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeError methodType:AKMethodTypeGetter tags:@[AKD_ACCOUNTS] message:[NSString stringWithFormat:@"%@, %@", error, error.userInfo]];
            }
            
            sharedManager.currentUser = (NSDictionary *)result;
            completionBlock(result);
        }];
        
    } failure:^{
        completionBlock(nil);
    }];
}

+ (void)fetchFriendsWithCompletion:(void (^)(NSDictionary *))completionBlock {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeGetter tags:@[AKD_DATA] message:nil];
    
    [FWFacebookManager checkForAccessTokenWithSuccess:^{
        
        
        
        NSArray *parameters = @[@"id", @"first_name", @"last_name", @"hometown", @"name", @"education", @"likes", @"permissions", @"friends"];
        FBSDKGraphRequest *request = [[FBSDKGraphRequest alloc] initWithGraphPath:@"/me/friends" parameters:@{FacebookAPIGraphRequestKey : [parameters componentsJoinedByString:@", "]} HTTPMethod:@"GET"];
        [request startWithCompletionHandler:^(FBSDKGraphRequestConnection *connection, id result, NSError *error) {
            
            if (error) {
                [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeError methodType:AKMethodTypeGetter tags:@[AKD_ACCOUNTS] message:[NSString stringWithFormat:@"%@, %@", error, error.userInfo]];
            }
            
            completionBlock(result);
        }];
        
    } failure:^{
        completionBlock(nil);
    }];
}

#pragma mark - // CATEGORY METHODS //

#pragma mark - // DELEGATED METHODS //

#pragma mark - // OVERWRITTEN METHODS //

- (void)setup {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_DATA, AKD_ACCOUNTS] message:nil];
    
    [super setup];
    
    [FBSDKProfile enableUpdatesOnAccessTokenChange:YES];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(currentUserDidChange:) name:FBSDKAccessTokenDidChangeUserID object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(profileDidChange:) name:FBSDKProfileDidChangeNotification object:nil];
}

- (void)teardown {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_DATA, AKD_ACCOUNTS] message:nil];
    
    [super teardown];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:FBSDKAccessTokenDidChangeUserID object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:FBSDKProfileDidChangeNotification object:nil];
}

#pragma mark - // PRIVATE METHODS (General) //

+ (instancetype)sharedManager {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeGetter tags:@[AKD_ACCOUNTS] message:nil];
    
    static FWFacebookManager *sharedManager = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedManager = [[FWFacebookManager alloc] init];
    });
    return sharedManager;
}

+ (void)checkForAccessTokenWithSuccess:(void (^)(void))successBlock failure:(void (^)(void))failureBlock {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeValidator tags:@[AKD_ACCOUNTS] message:nil];
    
    FBSDKAccessToken *accessToken = [FBSDKAccessToken currentAccessToken];
    if (!accessToken) {
        failureBlock();
        return;
    }
    
    if ([accessToken.expirationDate timeIntervalSinceNow] < 0) {
        [FBSDKAccessToken refreshCurrentAccessToken:^(FBSDKGraphRequestConnection *connection, id result, NSError *error) {
            
            if (error) {
                [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeError methodType:AKMethodTypeGetter tags:@[AKD_ACCOUNTS] message:[NSString stringWithFormat:@"%@, %@", error, error.userInfo]];
            }
            
            if (!result) {
                failureBlock();
                return;
            }
            
            successBlock();
        }];
    }
    
    successBlock();
}

#pragma mark - // PRIVATE METHODS (Responders) //

- (void)currentUserDidChange:(NSNotification *)notification {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeUnspecified tags:@[AKD_NOTIFICATION_CENTER, AKD_ACCOUNTS] message:nil];
    
    //
}

- (void)profileDidChange:(NSNotification *)notification {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeUnspecified tags:@[AKD_NOTIFICATION_CENTER, AKD_DATA] message:nil];
    
    self.currentProfile = notification.userInfo[FacebookAPINotificationKeyNewProfile];
    if (!self.currentProfile) {
        [FWFacebookManager sharedManager].currentUser = nil;
        [FBSDKAccessToken setCurrentAccessToken:nil];
    }
}

@end
