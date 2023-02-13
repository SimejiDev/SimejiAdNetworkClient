//
//  SANAdSizeDelegate.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANAdSize.h"

@class SANBannerView;

/// The class implementing this protocol will be notified when the SANBannerView's ad content
/// changes size. Any views that may be affected by the banner size change will have time to adjust.
@protocol SANAdSizeDelegate <NSObject>

/// Called before the ad view changes to the new size.
- (void)adView:(nonnull SANBannerView *)bannerView willChangeAdSizeTo:(SANAdSize)size;

@end
