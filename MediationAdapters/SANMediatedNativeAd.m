//  SANMediatedNativeAd.m
//  SANsdk
//
//  Created by SAN on 11/11/2021.
//  Copyright (c) 2021 SAN. All rights reserved.
//

#import "SANMediatedNativeAd.h"

@interface SANMediatedNativeAd ()
@property(nonatomic, strong) SANNativeAd *nativeAd;
@property(nonatomic, copy) NSArray *mappedImages;
@property(nonatomic, strong) GADNativeAdImage *mappedIcon;
@property(nonatomic, copy) NSDictionary *extras;
@property(nonatomic, strong) GADNativeAdViewAdOptions *nativeAdViewAdOptions;
@property(nonatomic, strong) SANAdChoicesView *adChoView;
@property(nonatomic, strong) SANMediaView *mediaView;

@end

@implementation SANMediatedNativeAd

- (instancetype)initWithSANNativeAd:(SANNativeAd *)sanNativeAd
              nativeAdViewAdOptions:(nullable GADNativeAdViewAdOptions *)nativeAdViewAdOptions {
    if (!sanNativeAd) {
        return nil;
    }
    
    self = [super init];
    if (self) {
        _nativeAd = sanNativeAd;
        _nativeAdViewAdOptions = nativeAdViewAdOptions;
        _adChoView = [[SANAdChoicesView alloc] init];
    }
    return self;
}

- (void)loadImages {
    NSMutableArray *images = [NSMutableArray array];
    for (SANNativeAdImage *object in _nativeAd.images) {
        if (object.image) {
            GADNativeAdImage *gadImage = [[GADNativeAdImage alloc] initWithImage:object.image];
            [images addObject:gadImage];
        } else if (object.imageURL) {
            GADNativeAdImage *gadImage = [[GADNativeAdImage alloc] initWithImage:[self loadImage:object.imageURL]];
            [images addObject:gadImage];
        }
    }
    _mappedImages = images;
    
    if (_nativeAd.icon.image) {
        _mappedIcon = [[GADNativeAdImage alloc] initWithImage:_nativeAd.icon.image];
    } else {
        NSURL *iconURL = [[NSURL alloc] initWithString:_nativeAd.iconURL];
        _mappedIcon = [[GADNativeAdImage alloc] initWithImage:[self loadImage:iconURL]];
    }
}

- (UIImage *)loadImage:(NSURL *)url {
    NSData *data = [NSData dataWithContentsOfURL:url];
    UIImage *image = [UIImage imageWithData: data];
    return image;
}

- (BOOL)hasVideoContent {
    return self.nativeAd.mediaContent.hasVideoContent;
}

- (UIView *)mediaView {
    if (!_mediaView && _nativeAd) {
        _mediaView = [[SANMediaView alloc] init];
        [_nativeAd fillMediaView:_mediaView];
    }
    return _mediaView;
}

- (NSString *)advertiser {
    return self.nativeAd.advertiser;
}

- (NSString *)headline {
    return self.nativeAd.headline;
}

- (NSArray *)images {
    return self.mappedImages;
}

- (NSString *)body {
    return self.nativeAd.body;
}

- (GADNativeAdImage *)icon {
    return self.mappedIcon;
}

- (NSString *)callToAction {
    return self.nativeAd.callToAction;
}

- (NSDecimalNumber *)starRating {
    return self.nativeAd.starRating;
}

- (NSString *)store {
    return self.nativeAd.store;
}

- (NSString *)price {
    return self.nativeAd.price;
}

- (NSDictionary *)extraAssets {
    return self.extras;
}

//- (UIView *)adChoicesView {
//    return self.adChoView;
//}

//- (UIView *)adInfoView {
//    return self.adChoView;
//}

- (void)didRenderInView:(UIView *)view
    clickableAssetViews:(NSDictionary<GADNativeAssetIdentifier, UIView *> *)clickableAssetViews
 nonclickableAssetViews:(NSDictionary<GADNativeAssetIdentifier, UIView *> *)nonclickableAssetViews
         viewController:(UIViewController *)viewController {
    if (self.nativeAd) {
        [self.nativeAd playVideo];
    }
    
    if (_adChoView) {
        CGFloat iconSize = 18.0;
        switch (_nativeAdViewAdOptions.preferredAdChoicesPosition) {
            case GADAdChoicesPositionTopLeftCorner:
                _adChoView.frame = CGRectMake(0, 0, iconSize, iconSize);
                _adChoView.autoresizingMask =
                UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleRightMargin;
                break;
            case GADAdChoicesPositionBottomLeftCorner:
                _adChoView.frame = CGRectMake(0, view.bounds.size.height - iconSize,
                                              iconSize, iconSize);
                _adChoView.autoresizingMask =
                UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleRightMargin;
                break;
            case GADAdChoicesPositionBottomRightCorner:
                _adChoView.frame =
                CGRectMake(view.bounds.size.width - iconSize,
                           view.bounds.size.height - iconSize, iconSize, iconSize);
                _adChoView.autoresizingMask =
                UIViewAutoresizingFlexibleTopMargin | UIViewAutoresizingFlexibleLeftMargin;
                break;
            case GADAdChoicesPositionTopRightCorner:
                _adChoView.frame =
                CGRectMake(view.bounds.size.width - iconSize, 0, iconSize, iconSize);
                _adChoView.autoresizingMask =
                UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleLeftMargin;
                break;
            default:
                _adChoView.frame =
                CGRectMake(view.bounds.size.width - iconSize, 0, iconSize, iconSize);
                _adChoView.autoresizingMask =
                UIViewAutoresizingFlexibleBottomMargin | UIViewAutoresizingFlexibleLeftMargin;
                break;
        }
        
        [view addSubview:_adChoView];
    }
}

- (void)didUntrackView:(UIView *)view {
    if (_adChoView) {
        [_adChoView removeFromSuperview];
    }
}

- (void)didRecordImpression {
    if (self.nativeAd) {
        [self.nativeAd recordImpression];
    }
}

- (void)didRecordClickOnAssetWithName:(GADNativeAssetIdentifier)assetName
                                 view:(UIView *)view
                       viewController:(UIViewController *)viewController {
    if (self.nativeAd) {
        [self.nativeAd handleClickOnView:view];
    }
}

@end
