//
//  SANSearchBannerView.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import "SANAdSizeDelegate.h"
#import "SANBannerView.h"

/// A view that displays search ads.
/// To show search ads:
///   1) Create a SANSearchBannerView and add it to your view controller's view hierarchy.
///   2) Create a SANDynamicHeightSearchRequest object to hold the search query and other search
///   data.
///   3) Call SANSearchBannerView's -loadRequest: method with the
///   SANDynamicHeightSearchRequest object.
@interface SANSearchBannerView : SANBannerView

/// If the banner view is initialized with kSANAdSizeFluid and the corresponding request is created
/// with dynamic height parameters, this delegate will be called when the ad size changes.
@property(nonatomic, weak, nullable) IBOutlet id<SANAdSizeDelegate> adSizeDelegate;

@end
