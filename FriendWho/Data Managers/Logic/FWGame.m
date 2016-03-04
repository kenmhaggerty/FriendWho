//
//  FWGame.m
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES (Private) //

#pragma mark - // IMPORTS (Private) //

#import "FWGame.h"
#import "AKDebugger.h"
#import "AKGenerics.h"

#import "FWUser.h"

#pragma mark - // DEFINITIONS (Private) //

NSUInteger const FWGameDefaultNumberOfQuestions = 10;
NSString * const FWGameAnswerKeyResponse = @"response";
NSString * const FWGameAnswerKeyResult = @"result";

@interface FWGame ()
@property (nonatomic, strong) NSOrderedSet <id <FWQuestion>> *questions;
@property (nonatomic, strong) NSMutableOrderedSet <NSDictionary *> *answers;
@property (nonatomic) NSUInteger currentIndex;
+ (NSOrderedSet <id <FWQuestion>> *)generateQuestions:(NSUInteger)numberOfQuestions forPlayer:(id <FWUser>)player;
@end

@implementation FWGame

#pragma mark - // SETTERS AND GETTERS //

#pragma mark - // INITS AND LOADS //

- (id)init {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_DATA] message:nil];
    
    id <FWUser_PRIVATE> user = [[FWUser alloc] init];
    return [[FWGame alloc] initWithPlayer:user numberOfQuestions:FWGameDefaultNumberOfQuestions];
}

- (id)initWithPlayer:(id<FWUser>)player numberOfQuestions:(NSUInteger)numberOfQuestions {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeSetup tags:@[AKD_DATA] message:nil];
    
    self = [super init];
    if (self) {
        _questions = [FWGame generateQuestions:numberOfQuestions forPlayer:player];
        _answers = [NSMutableOrderedSet orderedSetWithCapacity:numberOfQuestions];
        _currentIndex = 0;
    }
    
    return self;
}

#pragma mark - // PUBLIC METHODS (Gameplay) //

- (NSUInteger)numberOfQuestions {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeGetter tags:@[AKD_DATA] message:nil];
    
    return self.questions.count;
}

- (NSUInteger)numberOfCorrectAnswers {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeGetter tags:@[AKD_DATA] message:nil];
    
#warning TO DO – Check if this works
    NSPredicate *predicate = [NSPredicate predicateWithFormat:@"SELF.%K == %@", FWGameAnswerKeyResult, YES];
    NSOrderedSet *correctAnswers = [self.answers filteredOrderedSetUsingPredicate:predicate];
    return correctAnswers.count;
}

- (id <FWQuestion>)currentQuestion {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeGetter tags:@[AKD_DATA] message:nil];
    
    return self.questions[self.currentIndex];
}

#pragma mark - // CATEGORY METHODS //

#pragma mark - // DELEGATED METHODS //

#pragma mark - // OVERWRITTEN METHODS //

#pragma mark - // PRIVATE METHODS //

+ (NSOrderedSet <id <FWQuestion>> *)generateQuestions:(NSUInteger)numberOfQuestions forPlayer:(id <FWUser>)player {
    [AKDebugger logMethod:METHOD_NAME logType:AKLogTypeMethodName methodType:AKMethodTypeCreator tags:@[AKD_DATA] message:nil];
    
#warning TO DO – Implement +[FWGame generateQuestions:forPlayer:]
}

@end
