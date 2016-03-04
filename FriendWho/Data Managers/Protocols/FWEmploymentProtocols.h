//
//  FWEmploymentProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>
#import "FWDurationProtocols.h"

#import "FWCompanyProtocols.h"

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWEmployment) //

@protocol FWEmployment <FWDuration>

- (id <FWCompany>)company;
- (NSString *)role;
- (NSString *)department;

@end

#pragma mark - // PROTOCOL (FWEmployment_PRIVATE) //

@protocol FWEmployment_PRIVATE <FWEmployment>

// INITIALIZERS //

- (id)initWithCompany:(id <FWCompany>)company role:(NSString *)role department:(NSString *)department startDate:(id <FWDate>)startDate endDate:(id <FWDate>)endDate;

@end
