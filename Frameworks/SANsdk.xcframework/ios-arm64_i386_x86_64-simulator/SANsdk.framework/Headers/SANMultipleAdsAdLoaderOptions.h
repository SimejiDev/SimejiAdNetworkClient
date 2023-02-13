//
//  SANMultipleAdsAdLoaderOptions.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import "SANAdLoader.h"

/// Ad loader options for requesting multiple ads. Requesting multiple ads in a single request is
/// currently only available for native app install ads and native content ads.
@interface SANMultipleAdsAdLoaderOptions : SANAdLoaderOptions

/// Number of ads the SANAdLoader should attempt to return for the request. By default, numberOfAds
/// is one. Requests are invalid and will fail if numberOfAds is less than one. If numberOfAds
/// exceeds the maximum limit (5), only the maximum number of ads are requested.
///
/// The ad loader makes at least one and up to numberOfAds calls to the "ad received" and
/// -didFailToReceiveAdWithError: methods found in SANAdLoaderDelegate and its extensions, followed
/// by a single call to -adLoaderDidFinishLoading: once loading is finished.
@property(nonatomic) NSInteger numberOfAds;

@end
