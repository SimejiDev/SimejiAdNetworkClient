//
//  SANCustomEventRequest.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SANRequest.h"

@class SANCustomEventExtras;

/// Specifies optional ad request targeting parameters that are provided by the publisher and are
/// forwarded to custom events for purposes of populating an ad request to a 3rd party ad network.
@interface SANCustomEventRequest : NSObject

/// If the user's latitude, longitude, and accuracy are not specified, userHasLocation returns NO,
/// and userLatitude, userLongitude, and userLocationAccuracyInMeters return 0.
@property(nonatomic, readonly, assign) BOOL userHasLocation;

/// User's latitude set in SANRequest.
@property(nonatomic, readonly, assign) CGFloat userLatitude;

/// User's longitude set in SANRequest.
@property(nonatomic, readonly, assign) CGFloat userLongitude;

/// The accuracy, in meters, of the user's location data.
@property(nonatomic, readonly, assign) CGFloat userLocationAccuracyInMeters;

/// Description of the user's location, in free form text, set in SANRequest. If not available,
/// returns nil. This may be set even if userHasLocation is NO.
@property(nonatomic, readonly, copy, nullable) NSString *userLocationDescription;

/// Keywords set in SANRequest. Returns nil if no keywords are set.
@property(nonatomic, readonly, copy, nullable) NSArray *userKeywords;

/// The additional parameters set by the application. This property allows you to pass additional
/// information from your application to your Custom Event object. To do so, create an instance of
/// SANCustomEventExtras to pass to SANRequest -registerAdNetworkExtras:. The instance should have
/// an NSDictionary set for a particular custom event label. That NSDictionary becomes the
/// additionalParameters here.
@property(nonatomic, readonly, copy, nullable) NSDictionary *additionalParameters;

/// Indicates whether the testing property has been set in SANRequest.
@property(nonatomic, readonly, assign) BOOL isTesting;

@end
