//
//  FWLikeProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWLike) //

@protocol FWLike <NSObject>

- (NSString *)text;

@end

#pragma mark - // PROTOCOL (FWLike_PRIVATE) //

@protocol FWLike_PRIVATE <FWLike>

// INITIALIZERS //

- (id)initWithText:(NSString *)text;

@end
