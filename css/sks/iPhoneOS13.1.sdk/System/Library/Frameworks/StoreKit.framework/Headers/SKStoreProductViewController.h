//
//  SKStoreProductViewController.h
//  StoreKit
//
//  Copyright (c) 2012 Apple, Inc. All rights reserved.
//

#import <StoreKit/StoreKitDefines.h>

#if TARGET_OS_OSX
#import <AppKit/AppKit.h>
#else
#import <UIKit/UIKit.h>
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol SKStoreProductViewControllerDelegate;

/* View controller to display iTunes Store product information */
#if TARGET_OS_OSX
SK_EXTERN_CLASS API_AVAILABLE(ios(6.0)) API_UNAVAILABLE(macos) __TVOS_PROHIBITED @interface SKStoreProductViewController : NSViewController
#else
SK_EXTERN_CLASS API_AVAILABLE(ios(6.0)) API_UNAVAILABLE(macos) __TVOS_PROHIBITED @interface SKStoreProductViewController : UIViewController
#endif

// Delegate for product page events
@property(nonatomic, weak, nullable) id <SKStoreProductViewControllerDelegate> delegate API_AVAILABLE(ios(6.0)) API_UNAVAILABLE(macos) __TVOS_PROHIBITED;

// Load product view for the product with the given parameters.  See below for parameters (SKStoreProductParameter*).
// Block is invoked when the load finishes.
- (void)loadProductWithParameters:(NSDictionary<NSString *, id> *)parameters completionBlock:(nullable void(^)(BOOL result, NSError * __nullable error))block API_AVAILABLE(ios(6.0)) API_UNAVAILABLE(macos) __TVOS_PROHIBITED;

@end


@protocol SKStoreProductViewControllerDelegate <NSObject>

@optional

// Sent if the user requests that the page be dismissed
- (void)productViewControllerDidFinish:(SKStoreProductViewController *)viewController API_AVAILABLE(ios(6.0)) API_UNAVAILABLE(macos) __TVOS_PROHIBITED;

@end


// iTunes Store item identifier (NSNumber) of the product
SK_EXTERN NSString * const SKStoreProductParameterITunesItemIdentifier API_AVAILABLE(ios(6.0)) API_UNAVAILABLE(macos);

// SKU for the In-App Purchase product (NSString) to render at the top of the product page
SK_EXTERN NSString * const SKStoreProductParameterProductIdentifier API_AVAILABLE(ios(11.0)) API_UNAVAILABLE(macos);

// iTunes Store affiliate token (NSString)
SK_EXTERN NSString * const SKStoreProductParameterAffiliateToken API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos);

// iTunes Store affiliate campaign token (NSString)
SK_EXTERN NSString * const SKStoreProductParameterCampaignToken API_AVAILABLE(ios(8.0)) API_UNAVAILABLE(macos);

// Analytics provider token (NSString)
SK_EXTERN NSString * const SKStoreProductParameterProviderToken API_AVAILABLE(ios(8.3)) API_UNAVAILABLE(macos);

// Advertising partner token (NSString)
SK_EXTERN NSString * const SKStoreProductParameterAdvertisingPartnerToken API_AVAILABLE(ios(9.3)) API_UNAVAILABLE(macos);
NS_ASSUME_NONNULL_END
