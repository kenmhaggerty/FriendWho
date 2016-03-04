//
//  FWEnrollmentProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>
#import "FWDurationProtocols.h"

#import "FWPlaceProtocols.h"

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWEnrollment) //

@protocol FWEnrollment <FWDuration>

- (id <FWPlace>)school;
- (NSSet <NSString *> *)majors;
- (NSSet <NSString *> *)minors;

@end

#pragma mark - // PROTOCOL (FWEnrollment_PRIVATE) //

@protocol FWEnrollment_PRIVATE <FWEnrollment>

// INITIALIZERS //

- (id)initWithSchool:(id <FWPlace>)school startDate:(id <FWDate>)startDate endDate:(id <FWDate>)endDate;

// SETTERS //

- (void)setMajors:(NSSet <NSString *> *)majors;
- (void)addMajor:(NSString *)subject;
- (void)removeMajor:(NSString *)subject;

- (void)setMinors:(NSSet <NSString *> *)minors;
- (void)addMinor:(NSString *)subject;
- (void)removeMinor:(NSString *)subject;

@end
