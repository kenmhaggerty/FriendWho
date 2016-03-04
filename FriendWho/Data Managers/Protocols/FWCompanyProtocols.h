//
//  FWCompanyProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>

#import "FWUserProtocols.h"

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWCompany) //

@protocol FWCompany <NSObject>

- (NSString *)name;
- (NSSet <id <FWUser>> *)employees;

@end

#pragma mark - // PROTOCOL (FWCompany_PRIVATE) //

@protocol FWCompany_PRIVATE <FWCompany>

// INITIALIZERS //

- (id)initWithName:(NSString *)name;

// SETTERS //

- (void)setEmployees:(NSSet <id <FWUser>> *)employees;
- (void)addEmployee:(id <FWUser>)employee;
- (void)removeEmployee:(id <FWUser>)employee;

@end
