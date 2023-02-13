//
//  SANResponseInfo.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

/// Response metadata for an individual ad network in an ad response.
@interface SANAdNetworkResponseInfo : NSObject

/// A class name that identifies the ad network.
@property(nonatomic, readonly, nonnull) NSString *adNetworkClassName;

/// Network configuration set on the SAN UI.
@property(nonatomic, readonly, nonnull) NSDictionary<NSString *, id> *credentials;

/// Error associated with the request to the network. Nil if the network successfully loaded an ad
/// or if the network was not attempted.
@property(nonatomic, readonly, nullable) NSError *error;

/// Amount of time the ad network spent loading an ad. 0 if the network was not attempted.
@property(nonatomic, readonly) NSTimeInterval latency;

/// JSON-safe dictionary representation of the ad network response info.
@property(nonatomic, readonly, nonnull) NSDictionary<NSString *, id> *dictionaryRepresentation;

@end

/// Ad network class name for ads returned from SAN's ad network.
extern NSString *_Nonnull const SANSANAdNetworkClassName;

/// Ad network class name for custom event ads.
extern NSString *_Nonnull const SANCustomEventAdNetworkClassName;

/// Key into NSError.userInfo mapping to a SANResponseInfo object. When ads fail to load, errors
/// returned contain an instance of SANResponseInfo.
extern NSString *_Nonnull SANErrorUserInfoKeyResponseInfo;

/// Information about a response to an ad request.
@interface SANResponseInfo : NSObject

/// Unique identifier of the ad response.
@property(nonatomic, readonly, nullable) NSString *responseIdentifier;

/// A class name that identifies the ad network that returned the ad. Nil if no ad was returned.
@property(nonatomic, readonly, nullable) NSString *adNetworkClassName;

/// Array of metadata for each ad network included in the response.
@property(nonatomic, readonly, nonnull) NSArray<SANAdNetworkResponseInfo *> *adNetworkInfoArray;

/// JSON-safe dictionary representation of the response info.
@property(nonatomic, readonly, nonnull) NSDictionary<NSString *, id> *dictionaryRepresentation;

@end
