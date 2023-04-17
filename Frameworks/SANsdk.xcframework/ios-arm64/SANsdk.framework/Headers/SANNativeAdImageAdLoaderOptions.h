//
//  SANNativeAdImageAdLoaderOptions.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import "SANAdLoader.h"

/// Ad loader options for native ad image settings.
@interface SANNativeAdImageAdLoaderOptions : SANAdLoaderOptions

/// Indicates whether image asset content should be loaded by the SDK. If set to YES, the SDK will
/// not load image asset content and native ad image URLs can be used to fetch content. Defaults to
/// NO, image assets are loaded by the SDK.
@property(nonatomic, assign) BOOL disableImageLoading;

/// Indicates whether multiple images should be loaded for each asset. Defaults to NO.
@property(nonatomic, assign) BOOL shouldRequestMultipleImages;

@end
