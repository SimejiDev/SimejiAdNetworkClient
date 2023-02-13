//
//  SANAdLoader.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SANAdLoaderAdTypes.h"
#import "SANAdLoaderDelegate.h"
#import "SANRequest.h"

/// Ad loader options base class. See each ad type's header for available SANAdLoaderOptions
/// subclasses.
@interface SANAdLoaderOptions : NSObject
@end

/// Loads ads. See SANAdLoaderAdTypes.h for available ad types.
@interface SANAdLoader : NSObject

/// Object notified when an ad request succeeds or fails. Must conform to requested ad types'
/// delegate protocols.
@property(nonatomic, weak, nullable) id<SANAdLoaderDelegate> delegate;

/// The ad loader's ad unit ID.
@property(nonatomic, readonly, nonnull) NSString *adUnitID;

/// Indicates whether the ad loader is loading.
@property(nonatomic, getter=isLoading, readonly) BOOL loading;

/// Returns an initialized ad loader configured to load the specified ad types.
///
/// @param rootViewController The root view controller is used to present ad click actions.
/// @param adTypes An array of ad types. See SANAdLoaderAdTypes.h for available ad types.
/// @param options An array of SANAdLoaderOptions objects to configure how ads are loaded, or nil
/// to use default options. See each ad type's header for available SANAdLoaderOptions subclasses.
- (nonnull instancetype)initWithAdUnitID:(nonnull NSString *)adUnitID
                      rootViewController:(nullable UIViewController *)rootViewController
                                 adTypes:(nonnull NSArray<SANAdLoaderAdType> *)adTypes
                                 options:(nullable NSArray<SANAdLoaderOptions *> *)options;

/// Loads the ad and informs the delegate of the outcome.
- (void)loadRequest:(nullable SANRequest *)request;

@end
