//
//  FWDateProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>

#pragma mark - // DEFINITIONS //

typedef enum : NSUInteger {
    Sunday = 0;
    Monday = 1,
    Tuesday = 2,
    Wednesday = 3,
    Thursday = 4,
    Friday = 5,
    Saturday = 6
} FWDay;

typedef enum : NSUInteger {
    Aries = 0,
    Taurus = 1,
    Gemini = 2,
    Cancer = 3,
    Leo = 4,
    Virgo = 5,
    Libra = 6,
    Scorpio = 7,
    Saggitarius = 8,
    Capricorn = 9,
    Aquarius = 10,
    Pisces = 11
} FWZodiacSign;

typedef enum : NSUInteger {
    Rat = 0,
    Ox = 1,
    Tiger = 2,
    Rabbit = 3,
    Dragon = 4,
    Snake = 5,
    Horse = 6,
    Goat = 7,
    Monkey = 8,
    Rooster = 9,
    Dog = 10,
    Pig = 11
} FWZodiacYear;

#pragma mark - // PROTOCOL (FWDate) //

@protocol FWDate <NSObject>

- (NSDate *)date;
- (NSNumber *)day;
- (NSNumber *)month;
- (NSNumber *)year;
- (FWDay)dayOfWeek;

@end

#pragma mark - // PROTOCOL (FWDate_PRIVATE) //

@protocol FWDate_PRIVATE <FWDate>

// INITIALIZERS //

- (id)initWithDay:(NSNumber *)day month:(NSNumber *)month year:(NSNumber *)year;

@end

#pragma mark - // PROTOCOL (FWBirthday) //

@protocol FWBirthday <FWDate>

- (NSNumber *)age;
- (FWZodiacSign)zodiacSign;
- (FWZodiacYear)zodiacYear;

@end

#pragma mark - // PROTOCOL (FWBirthday_PRIVATE) //

@protocol FWBirthday_PRIVATE <FWBirthday, FWDate_PRIVATE>

// no additional methods

@end
