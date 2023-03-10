//
//  SANRequest.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SANAdNetworkExtras.h"
#import "SANMobileAdsDefines.h"

/// Add this constant to the testDevices property's array to receive test ads on the simulator.
SAN_EXTERN NSString *_Nonnull const kSANSimulatorID;

/// Deprecated gender constants.
typedef NS_ENUM(NSInteger, SANGender) {
  kSANGenderUnknown,  ///< Deprecated.
  kSANGenderMale,     ///< Deprecated.
  kSANGenderFemale    ///< Deprecated.
};

/// Specifies optional parameters for ad requests.
@interface SANRequest : NSObject <NSCopying>

/// Returns a default request.
+ (nonnull instancetype)request;

#pragma mark Additional Parameters For Ad Networks

/// Ad networks may have additional parameters they accept. To pass these parameters to them, create
/// the ad network extras object for that network, fill in the parameters, and register it here. The
/// ad network should have a header defining the interface for the 'extras' object to create. All
/// networks will have access to the basic settings you've set in this SANRequest. If you register
/// an extras object that is the same class as one you have registered before, the previous extras
/// will be overwritten.
- (void)registerAdNetworkExtras:(nonnull id<SANAdNetworkExtras>)extras;

/// Returns the network extras defined for an ad network.
- (nullable id<SANAdNetworkExtras>)adNetworkExtrasFor:(nonnull Class<SANAdNetworkExtras>)aClass;

/// Removes the extras for an ad network. |aClass| is the class which represents that network's
/// extras type.
- (void)removeAdNetworkExtrasFor:(nonnull Class<SANAdNetworkExtras>)aClass;

#pragma mark Publisher Provided

/// Scene object. Used in multiscene apps to request ads of the appropriate size.
@property(nonatomic, nullable, weak) UIWindowScene *scene API_AVAILABLE(ios(13.0));

#pragma mark User Information

/// The user's current location. Location data is not used to target SAN ads; however, it may be
/// used by 3rd party ad networks. Do not use Core Location just for advertising. Your app should
/// have a valid use case for it as well.
- (void)setLocationWithLatitude:(CGFloat)latitude
                      longitude:(CGFloat)longitude
                       accuracy:(CGFloat)accuracyInMeters;

#pragma mark Contextual Information

/// Array of keyword strings. Keywords are words or phrases describing the current user activity
/// such as @"Sports Scores" or @"Football". Set this property to nil to clear the keywords.
@property(nonatomic, copy, nullable) NSArray<NSString *> *keywords;

/// URL string for a webpage whose content matches the app's primary content. This webpage content
/// is used for targeting and brand safety purposes.
@property(nonatomic, copy, nullable) NSString *contentURL;

/// URL strings for non-primary web content near an ad. Promotes brand safety and allows displayed
/// ads to have an app level rating (MA, T, PG, etc) that is more appropriate to neighboring
/// content.
@property(nonatomic, copy, nullable) NSArray<NSString *> *neighboringContentURLStrings;

#pragma mark Request Agent Information

/// String that identifies the ad request's origin. Third party libraries that reference the Mobile
/// Ads SDK should set this property to denote the platform from which the ad request originated.
/// For example, a third party ad network called "CoolAds network" that is mediating requests to the
/// Mobile Ads SDK should set this property as "CoolAds".
@property(nonatomic, copy, nullable) NSString *requestAgent;

@end
