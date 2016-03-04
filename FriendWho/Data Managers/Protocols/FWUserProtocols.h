//
//  FWUserProtocols.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//

#pragma mark - // NOTES //

#pragma mark - // IMPORTS //

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "FWDateProtocols.h"
#import "FWEnrollmentProtocols.h"
#import "FWEmploymentProtocols.h"
#import "FWBookProtocols.h"
#import "FWMusicProtocols.h"
#import "FWRelationshipProtocols.h"
#import "FWReligionProtocols.h"
#import "FWPoliticsProtocols.h"
#import "FWPlaceProtocols.h"

#pragma mark - // DEFINITIONS //

#pragma mark - // PROTOCOL (FWUser) //

@protocol FWUser <NSObject>

- (NSString *)name;
- (UIImage *)profilePhoto;
- (NSString *)bio;
- (id <FWBirthday>)birthday;
- (NSSet <id <FWUser>> *)friends;
- (NSSet <id <FWEnrollment>> *)education;
- (NSSet <id <FWEmployment>> *)employment;
- (NSSet <id <FWBook>> *)favoriteBooks;
- (NSSet <id <FWMusic>> *)favoriteMusic;
- (NSSet *)likes;
- (NSSet <id <FWRelationship>> *)relationships;
- (id <FWReligion>)religion;
- (id <FWPolitics>)politics;
- (NSSet <id <FWPlace>> *)places;

@end

#pragma mark - // PROTOCOL (FWUser_PRIVATE) //

@protocol FWUser_PRIVATE <NSObject>

// INITIALIZERS //

- (id)initWithName:(NSString *)name photo:(UIImage *)profilePhoto;

// SETTERS //

- (void)setName:(NSString *)name;
- (void)setProfilePhoto:(UIImage *)profilePhoto;
- (void)setBio:(NSString *)bio;
- (void)setBirthday:(id <FWDate>)birthday;
- (void)setFriends:(NSSet <id <FWUser>> *)friends;
- (void)setEducation:(NSSet <id <FWEnrollment>> *)education;
- (void)setEmployment:(NSSet <id <FWEmployment>> *)employment;
- (void)setFavoriteBooks:(NSSet <id <FWBook>> *)favoriteBooks;
- (void)setFavoriteMusic:(NSSet <id <FWMusic>> *)favoriteMusic;
- (void)setLikes:(NSSet *)likes;
- (void)setRelationships:(NSSet <id <FWRelationship>> *)relationships;
- (void)setReligion:(id <FWReligion>)religion;
- (void)setPolitics:(id <FWPolitics>)politics;
- (void)setPlaces:(NSSet <id <FWPlace>> *)places;

@end
