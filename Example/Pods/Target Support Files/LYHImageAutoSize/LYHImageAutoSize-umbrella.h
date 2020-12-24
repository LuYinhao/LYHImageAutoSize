#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "LYHImageAutoSize.h"
#import "LYHImageAutoSizeCache.h"
#import "LYHImageAutoSizeConst.h"
#import "NSString+LYHImageAutoSize.h"
#import "UICollectionView+LYHImageAutoSize.h"
#import "UITableView+LYHImageAutoSize.h"

FOUNDATION_EXPORT double LYHImageAutoSizeVersionNumber;
FOUNDATION_EXPORT const unsigned char LYHImageAutoSizeVersionString[];

