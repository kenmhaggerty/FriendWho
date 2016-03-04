//
//  FWViewController.m
//  FriendWho
//
//  Created by Ken M. Haggerty on 2/29/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES (Private) //

#pragma mark - // IMPORTS (Private) //

#import "FWViewController.h"
#import "AKDebugger.h"
#import "AKGenerics.h"
#import "FBSDKCoreKit.h"
#import "FBSDKLoginKit.h"
#import "FWFacebookManager.h"

#pragma mark - // DEFINITIONS (Private) //

@interface FWViewController () <FBSDKLoginButtonDelegate>
@property (nonatomic, strong) IBOutlet FBSDKProfilePictureView *profilePictureView;
@property (nonatomic, strong) IBOutlet UILabel *nameLabel;
@property (nonatomic, strong) IBOutlet FBSDKLoginButton *loginButton;
- (IBAction)info:(id)sender;
@end

@implementation FWViewController

#pragma mark - // SETTERS AND GETTERS //

#pragma mark - // INITS AND LOADS //

- (void)dealloc {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_UI] message:nil];
    
    [self teardown];
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_UI] message:nil];
    
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        [self setup];
    }
    
    return self;
}

- (void)awakeFromNib {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_UI] message:nil];
    
    [super awakeFromNib];
    
    [self setup];
}

- (void)viewDidLoad {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_UI] message:nil];
    
    [super viewDidLoad];
    
    self.loginButton.readPermissions = [FWFacebookManager permissions];
}

- (void)viewWillAppear:(BOOL)animated {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_UI] message:nil];
    
    [super viewWillAppear:animated];
    
    [FWFacebookManager fetchCurrentProfileWithCompletion:^(NSDictionary *currentUser) {
        self.nameLabel.text = currentUser[FacebookAPIUserKeyName];
    }];
}

#pragma mark - // PUBLIC METHODS //

#pragma mark - // CATEGORY METHODS //

#pragma mark - // DELEGATED METHODS (FBSDKLoginButtonDelegate) //

- (void)loginButton:(FBSDKLoginButton *)loginButton didCompleteWithResult:(FBSDKLoginManagerLoginResult *)result error:(NSError *)error {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeUnspecified tags:@[AKD_ACCOUNTS] message:nil];
    
    //
}

- (void)loginButtonDidLogOut:(FBSDKLoginButton *)loginButton {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeUnspecified tags:@[AKD_ACCOUNTS] message:nil];
    
    self.nameLabel.text = nil;
}

#pragma mark - // OVERWRITTEN METHODS //

- (void)setup {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_UI] message:nil];
    
    [super setup];
}

#pragma mark - // PRIVATE METHODS //

- (IBAction)info:(id)sender {
    [FWFacebookManager fetchFriendsWithCompletion:^(NSDictionary *result) {
        //
    }];
}

@end
