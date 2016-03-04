//
//  FWBookProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWBook) //

@protocol FWBook <NSObject>

- (NSString *)title;
- (NSString *)author;

@end

#pragma mark - // PROTOCOL (FWBook_PRIVATE) //

@protocol FWBook_PRIVATE <FWBook>

// INITIALIZERS //

- (id)initWithTitle:(NSString *)title author:(NSString *)author;

@end
