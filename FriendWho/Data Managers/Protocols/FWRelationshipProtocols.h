//
//  FWRelationshipProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>
#import "FWDurationProtocols.h"

#import "FWUserProtocols.h"

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOLS //

@protocol FWRelationship <FWDuration>

- (id <FWUser>)person;
- (NSString *)relation;

@end

#pragma mark - // PROTOCOL (FWRelationship_PRIVATE) //

@protocol FWRelationship_PRIVATE <FWRelationship>

// INITIALIZERS //

- (id)initWithPerson:(id <FWUser>)person relation:(NSString *)relationship startDate:(id <FWDate>)startDate endDate:(id <FWDate>)endDate;

@end
