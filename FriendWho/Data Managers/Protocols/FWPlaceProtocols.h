//
//  FWPlaceProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL //

@protocol FWPlace <NSObject>

- (NSString *)name;
- (NSString *)street;
- (NSString *)city;
- (NSString *)state;
- (NSString *)zip;
- (NSString *)country;
- (CLLocationCoordinate2D)coordinates;

@end

#pragma mark - // PROTOCOL (FWPlace_PRIVATE) //

@protocol FWPlace_PRIVATE <FWPlace>

// INITIALIZERS //

- (id)initWithName:(NSString *)name coordinates:(CLLocationCoordinate2D)coordinates;

// SETTERS //

- (void)setStreet:(NSString *)street;
- (void)setCity:(NSString *)city;
- (void)setState:(NSString *)state;
- (void)setZip:(NSString *)zip;
- (void)setCountry:(NSString *)country;

@end
