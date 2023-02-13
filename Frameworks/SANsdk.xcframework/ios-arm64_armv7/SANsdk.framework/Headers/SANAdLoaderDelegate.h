//
//  SANAdLoaderDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SANAdLoader;

/// Base ad loader delegate protocol. Ad types provide extended protocols that declare methods to
/// handle successful ad loads.
@protocol SANAdLoaderDelegate <NSObject>

/// Called when adLoader fails to load an ad.
- (void)adLoader:(nonnull SANAdLoader *)adLoader
    didFailToReceiveAdWithError:(nonnull NSError *)error;

@optional

/// Called after adLoader has finished loading.
- (void)adLoaderDidFinishLoading:(nonnull SANAdLoader *)adLoader;

@end
