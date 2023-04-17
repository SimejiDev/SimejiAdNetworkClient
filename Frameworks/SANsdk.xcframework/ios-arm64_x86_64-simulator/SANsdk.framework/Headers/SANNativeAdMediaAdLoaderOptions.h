//
//  SANNativeAdMediaAdLoaderOptions.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import "SANAdLoader.h"
#import "SANMediaAspectRatio.h"

/// Ad loader options for native ad media settings.
@interface SANNativeAdMediaAdLoaderOptions : SANAdLoaderOptions

/// Image and video aspect ratios. Defaults to SANMediaAspectRatioUnknown. Portrait, landscape, and
/// square aspect ratios are returned when this property is SANMediaAspectRatioUnknown or
/// SANMediaAspectRatioAny.
@property(nonatomic, assign) SANMediaAspectRatio mediaAspectRatio;

@end
