//
//  FWMusicProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWMusic) //

@protocol FWMusic <NSObject>

- (NSString *)song;
- (NSString *)album;
- (NSString *)band;

@end

#pragma mark - // PROTOCOL (FWMusic_PRIVATE) //

@protocol FWMusic_PRIVATE <NSObject>

// INITIALIZERS //

- (id)initWithSong:(NSString *)song album:(NSString *)album band:(NSString *)band;

@end
