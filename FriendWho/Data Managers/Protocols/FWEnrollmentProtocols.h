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

#import "FWDateProtocols.h"
#import "FWSchoolProtocols.h"
#import "FWSubjectProtocols.h"

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWEnrollment) //

@protocol FWEnrollment <NSObject>

- (id <FWDate>)startDate;
- (id <FWDate>)endDate;
- (NSNumber *)durationInYears;
- (id <FWSchool>)school;
- (NSSet <id <FWSubject>> *)majors;
- (NSSet <id <FWSubject>> *)minors;

@end

#pragma mark - // PROTOCOL (FWEnrollment_PRIVATE) //

@protocol FWEnrollment_PRIVATE <FWEnrollment>

// INITIALIZERS //

- (id)initWithSchool:(id <FWSchool>)school startDate:(id <FWDate>)startDate endDate:(id <FWDate>)endDate;

// SETTERS //

- (void)setMajors:(NSSet <id <FWSubject>> *)majors;
- (void)addMajor:(id <FWSubject>)subject;
- (void)removeMajor:(id <FWSubject>)subject;

- (void)setMinors:(NSSet <id <FWSubject>> *)minors;
- (void)addMinor:(id <FWSubject>)subject;
- (void)removeMinor:(id <FWSubject>)subject;

@end
