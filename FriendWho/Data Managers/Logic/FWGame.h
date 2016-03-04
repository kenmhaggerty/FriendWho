//
//  FWGame.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES (Public) //

#pragma mark - // IMPORTS (Public) //

#import <Foundation/Foundation.h>

#import "FWUserProtocols.h"
#import "FWQuestionProtocols.h"

#pragma mark - // PROTOCOLS //

#pragma mark - // DEFINITIONS (Public) //

@interface FWGame : NSObject

// INITIALIZERS //

- (id)init;
- (id)initWithPlayer:(id <FWUser>)player numberOfQuestions:(NSUInteger)numberOfQuestions;

// GAMEPLAY //

- (NSUInteger)numberOfQuestions;
- (NSUInteger)numberOfCorrectAnswers;
- (id <FWQuestion>)currentQuestion;

@end
