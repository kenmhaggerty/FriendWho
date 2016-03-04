//
//  FWFacebookManager.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 2/29/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES (Public) //

#pragma mark - // IMPORTS (Public) //

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "NSObject+Basics.h"

#pragma mark - // PROTOCOLS //

#pragma mark - // DEFINITIONS (Public) //

extern NSString * const FacebookAPIPermissionPublicProfile;
extern NSString * const FacebookAPIPermissionFriends;
extern NSString * const FacebookAPIPermissionEmail;
extern NSString * const FacebookAPIPermissionAboutMe;
extern NSString * const FacebookAPIPermissionBooks;
extern NSString * const FacebookAPIPermissionFitness;
extern NSString * const FacebookAPIPermissionMusic;
extern NSString * const FacebookAPIPermissionNews;
extern NSString * const FacebookAPIPermissionWatchedVideos;
extern NSString * const FacebookAPIPermissionBirthday;
extern NSString * const FacebookAPIPermissionEducation;
extern NSString * const FacebookAPIPermissionEvents;
extern NSString * const FacebookAPIPermissionGamesActivity;
extern NSString * const FacebookAPIPermissionHometown;
extern NSString * const FacebookAPIPermissionLikes;
extern NSString * const FacebookAPIPermissionLocation;
extern NSString * const FacebookAPIPermissionManagedGroups;
extern NSString * const FacebookAPIPermissionPhotos;
extern NSString * const FacebookAPIPermissionPosts;
extern NSString * const FacebookAPIPermissionRelationships;
extern NSString * const FacebookAPIPermissionRelationshipDetails;
extern NSString * const FacebookAPIPermissionReligionAndPolitics;
extern NSString * const FacebookAPIPermissionTaggedPlaces;
extern NSString * const FacebookAPIPermissionVideos;
extern NSString * const FacebookAPIPermissionWebsite;
extern NSString * const FacebookAPIPermissionEmployment;

extern NSString * const FacebookAPIUserKeyID;
extern NSString * const FacebookAPIUserKeyName;

@interface FWFacebookManager : NSObject

// SETUP //

+ (void)applicationDidBecomeActive;
+ (void)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
+ (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation;

@end
