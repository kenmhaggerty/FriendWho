//
//  FWDurationProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>

#import "FWDateProtocols.h"

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWDuration) //

@protocol FWDuration <NSObject>

- (id <FWDate>)startDate;
- (id <FWDate>)endDate;
- (NSNumber *)durationInYears;

@end

#pragma mark - // PROTOCOL (FWDuration_PRIVATE) //

@protocol FWDuration_PRIVATE <FWDuration>

// INITIALIZERS //

- (id)initWithStartDate:(id <FWDate>)startDate endDate:(id <FWDate>)endDate;

@end
