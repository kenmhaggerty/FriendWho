//
//  FWUser+CoreDataProperties.h
//  FriendWho
//
//  Created by Ken M. Haggerty on 3/4/16.
//  Copyright © 2016 Flatiron School. All rights reserved.
//
//  Choose "Create NSManagedObject Subclass…" from the Core Data editor menu
//  to delete and recreate this implementation file for your updated model.
//

#import "FWUser.h"

NS_ASSUME_NONNULL_BEGIN

@interface FWUser (CoreDataProperties)

@property (nullable, nonatomic, retain) NSString *name;
@property (nullable, nonatomic, retain) NSData *profilePhoto;
@property (nullable, nonatomic, retain) NSString *bio;
@property (nullable, nonatomic, retain) NSString *religion;
@property (nullable, nonatomic, retain) NSString *politics;

@property (nullable, nonatomic, retain) NSManagedObject *birthday;
@property (nullable, nonatomic, retain) NSSet <NSManagedObject *> *friends;
@property (nullable, nonatomic, retain) NSSet <NSManagedObject *> *education;
@property (nullable, nonatomic, retain) NSSet <NSManagedObject *> *employment;
@property (nullable, nonatomic, retain) NSSet <NSManagedObject *> *favoriteBooks;
@property (nullable, nonatomic, retain) NSSet <NSManagedObject *> *favoriteMusic;
@property (nullable, nonatomic, retain) NSSet <NSManagedObject *> *likes;
@property (nullable, nonatomic, retain) NSSet <NSManagedObject *> *relationships;
@property (nullable, nonatomic, retain) NSSet <NSManagedObject *> *places;

@end

@interface FWUser (CoreDataGeneratedAccessors)

- (void)addFriendsObject:(NSManagedObject *)value;
- (void)removeFriendsObject:(NSManagedObject *)value;
- (void)addFriends:(NSSet <NSManagedObject *> *)values;
- (void)removeFriends:(NSSet <NSManagedObject *> *)values;

- (void)addEducationObject:(NSManagedObject *)value;
- (void)removeEducationObject:(NSManagedObject *)value;
- (void)addEducation:(NSSet <NSManagedObject *> *)values;
- (void)removeEducation:(NSSet <NSManagedObject *> *)values;

- (void)addEmploymentObject:(NSManagedObject *)value;
- (void)removeEmploymentObject:(NSManagedObject *)value;
- (void)addEmployment:(NSSet <NSManagedObject *> *)values;
- (void)removeEmployment:(NSSet <NSManagedObject *> *)values;

- (void)addFavoriteBooksObject:(NSManagedObject *)value;
- (void)removeFavoriteBooksObject:(NSManagedObject *)value;
- (void)addFavoriteBooks:(NSSet <NSManagedObject *> *)values;
- (void)removeFavoriteBooks:(NSSet <NSManagedObject *> *)values;

- (void)addFavoriteMusicObject:(NSManagedObject *)value;
- (void)removeFavoriteMusicObject:(NSManagedObject *)value;
- (void)addFavoriteMusic:(NSSet <NSManagedObject *> *)values;
- (void)removeFavoriteMusic:(NSSet <NSManagedObject *> *)values;

- (void)addLikesObject:(NSManagedObject *)value;
- (void)removeLikesObject:(NSManagedObject *)value;
- (void)addLikes:(NSSet <NSManagedObject *> *)values;
- (void)removeLikes:(NSSet <NSManagedObject *> *)values;

- (void)addRelationshipsObject:(NSManagedObject *)value;
- (void)removeRelationshipsObject:(NSManagedObject *)value;
- (void)addRelationships:(NSSet <NSManagedObject *> *)values;
- (void)removeRelationships:(NSSet <NSManagedObject *> *)values;

- (void)addPlacesObject:(NSManagedObject *)value;
- (void)removePlacesObject:(NSManagedObject *)value;
- (void)addPlaces:(NSSet <NSManagedObject *> *)values;
- (void)removePlaces:(NSSet <NSManagedObject *> *)values;

@end

NS_ASSUME_NONNULL_END
