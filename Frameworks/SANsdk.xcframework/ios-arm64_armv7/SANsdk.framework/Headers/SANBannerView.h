//
//  SANBannerView.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SANAdSize.h"
#import "SANAdSizeDelegate.h"
#import "SANAdValue.h"
#import "SANBannerViewDelegate.h"
#import "SANRequest.h"
#import "SANResponseInfo.h"

/// A view that displays banner ads
@interface SANBannerView : UIView

#pragma mark Initialization

/// Initializes and returns a banner view with the specified ad size and origin relative to the
/// banner's superview.
- (nonnull instancetype)initWithAdSize:(SANAdSize)adSize origin:(CGPoint)origin;

/// Initializes and returns a banner view with the specified ad size placed at its superview's
/// origin.
- (nonnull instancetype)initWithAdSize:(SANAdSize)adSize;

#pragma mark Pre-Request

/// Required value created on the SAN website. Create a new ad unit for every unique placement of
/// an ad in your application. Set this to the ID assigned for this placement. Ad units are
/// important for targeting and statistics.
///
@property(nonatomic, copy, nullable) IBInspectable NSString *adUnitID;

/// Required reference to a root view controller that is used by the banner to present full screen
/// content after the user interacts with the ad. The root view controller is most commonly the view
/// controller displaying the banner.
@property(nonatomic, weak, nullable) IBOutlet UIViewController *rootViewController;

/// Required to set this banner view to a proper size. Never create your own SANAdSize directly.
/// Use one of the predefined standard ad sizes (such as kSANAdSizeBanner), or create one using the
/// SANAdSizeFromCGSize method. If not using mediation, then changing the adSize after an ad has
/// been shown will cause a new request (for an ad of the new size) to be sent. If using mediation,
/// then a new request may not be sent.
@property(nonatomic, assign) SANAdSize adSize;

/// Optional delegate object that receives state change notifications from this SANBannerView.
/// Typically this is a UIViewController.
@property(nonatomic, weak, nullable) IBOutlet id<SANBannerViewDelegate> delegate;

/// Optional delegate that is notified when creatives cause the banner to change size.
@property(nonatomic, weak, nullable) IBOutlet id<SANAdSizeDelegate> adSizeDelegate;

#pragma mark Making an Ad Request

/// Requests an ad. The request object supplies targeting information.
- (void)loadRequest:(nullable SANRequest *)request;

/// A Boolean value that determines whether autoloading of ads in the receiver is enabled. If
/// enabled, you do not need to call the loadRequest: method to load ads.
@property(nonatomic, assign, getter=isAutoloadEnabled) IBInspectable BOOL autoloadEnabled;

#pragma mark Response

/// Information about the ad response that returned the current ad or an error. Nil until the first
/// ad request succeeds or fails.
@property(nonatomic, readonly, nullable) SANResponseInfo *responseInfo;

/// Called when ad is estimated to have earned money. Available for allowlisted accounts only.
@property(nonatomic, nullable, copy) SANPaidEventHandler paidEventHandler;

@end
