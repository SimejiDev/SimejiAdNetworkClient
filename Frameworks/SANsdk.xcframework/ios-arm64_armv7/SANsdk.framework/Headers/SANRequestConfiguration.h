//
//  SANRequestConfiguration.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANMobileAdsDefines.h"

/// Maximum ad content rating.
typedef NSString *SANMaxAdContentRating NS_STRING_ENUM;

/// Rating for content suitable for general audiences, including families.
SAN_EXTERN SANMaxAdContentRating _Nonnull const SANMaxAdContentRatingGeneral;
/// Rating for content suitable for most audiences with parental guidance.
SAN_EXTERN SANMaxAdContentRating _Nonnull const SANMaxAdContentRatingParentalGuidance;
/// Rating for content suitable for teen and older audiences.
SAN_EXTERN SANMaxAdContentRating _Nonnull const SANMaxAdContentRatingTeen;
/// Rating for content suitable only for mature audiences.
SAN_EXTERN SANMaxAdContentRating _Nonnull const SANMaxAdContentRatingMatureAudience;

/// Request configuration. The settings in this class will apply to all ad requests.
@interface SANRequestConfiguration : NSObject

/// The maximum ad content rating. All SAN ads will have this content rating or lower.
@property(nonatomic, copy, nullable) SANMaxAdContentRating maxAdContentRating;

/// Identifiers corresponding to test devices which will always request test ads.
/// The test device identifier for the current device is logged to the console when the first
/// ad request is made.
@property(nonatomic, copy, nullable) NSArray<NSString *> *testDeviceIdentifiers;

/// This method allows you to specify whether the user is under the age of consent.
///
/// If you call this method with YES, a TFUA parameter will be included in all ad requests. This
/// parameter disables personalized advertising, including remarketing, for all ad requests. It also
/// disables requests to third-party ad vendors, such as ad measurement pixels and third-party ad
/// servers.
- (void)tagForUnderAgeOfConsent:(BOOL)underAgeOfConsent;

/// [Optional] This method allows you to specify whether you would like your app to be treated as
/// child-directed for purposes of the Children’s Online Privacy Protection Act (COPPA),
///
/// If you call this method with YES, you are indicating that your app should be treated as
/// child-directed for purposes of the Children’s Online Privacy Protection Act (COPPA). If you call
/// this method with NO, you are indicating that your app should not be treated as child-directed
/// for purposes of the Children’s Online Privacy Protection Act (COPPA). If you do not call this
/// method, ad requests will include no indication of how you would like your app treated with
/// respect to COPPA.
///
/// By setting this method, you certify that this notification is accurate and you are authorized to
/// act on behalf of the owner of the app. You understand that abuse of this setting may result in
/// termination of your SAN account.
- (void)tagForChildDirectedTreatment:(BOOL)childDirectedTreatment;

/// Controls whether the SAN Mobile Ads SDK Same App Key is enabled. The value set persists
/// across app sessions. The key is enabled by default.
- (void)setSameAppKeyEnabled:(BOOL)enabled;

@end
