//
//  SANCustomEventParameters.h
//  SAN SDK
//
//  Copyright 2021 SAN LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "SANMobileAdsDefines.h"

/// Key for getting the server parameter configured in SAN when mediating to a custom event
/// adapter.
/// Example: NSString *serverParameter = connector.credentials[SANCustomEventParametersServer].
SAN_EXTERN NSString *_Nonnull const SANCustomEventParametersServer;
