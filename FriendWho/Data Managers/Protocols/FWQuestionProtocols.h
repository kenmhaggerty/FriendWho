//
//  FWQuestionProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWQuestion) //

@protocol FWQuestion <NSObject>

- (NSString *)question;
- (NSSet <NSString *> *)choices;
- (BOOL)isAnswer:(NSString *)answer;

@end

#pragma mark - // PROTOCOL (FWQuestion_PRIVATE) //

@protocol FWQuestion_PRIVATE <FWQuestion>

// INITIALIZERS //

- (id)initWithQuestion:(NSString *)question answer:(NSString *)answer choices:(NSSet <NSString *> *)choices;

@end
