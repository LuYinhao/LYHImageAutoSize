//
//  LYHImageAutoSize.h
//  LYHImageHeightLayoutExample
//
//  Created by Lucas on 09/28/2020.
//  Copyright (c) 2020 Lucas. All rights reserved.
//  http://git.swste.com/lucas/LYHImageAutoSize

//  版本:1.0.0


//  使用说明:https://github.com/CoderZhuXH/LYHImageAutoSize/blob/master/README.md

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "UITableView+LYHImageAutoSize.h"
#import "UICollectionView+LYHImageAutoSize.h"
#import "LYHImageAutoSizeCache.h"

NS_ASSUME_NONNULL_BEGIN
@interface LYHImageAutoSize : NSObject

/**
 *  Get image height
 *
 *  @param url            imageURL
 *  @param layoutWidth    layoutWidth
 *  @param estimateHeight estimateHeight(default 100)
 *
 *  @return imageHeight
 */
+(CGFloat)imageHeightForURL:(NSURL *)url layoutWidth:(CGFloat)layoutWidth estimateHeight:(CGFloat )estimateHeight;

/**
 *  Get image width
 *
 *  @param url            imageURL
 *  @param layoutHeight   layoutHeight
 *  @param estimateWidth estimateWidth(default 90)
 *
 *  @return imageHeight
 */
+(CGFloat)imageWidthForURL:(NSURL *)url layoutHeight:(CGFloat)layoutHeight estimateWidth:(CGFloat )estimateWidth;

/**
 *  Get image size from cache,query the disk cache synchronously after checking the memory cache
 *
 *  @param url imageURL
 *
 *  @return imageSize
 */
+(CGSize )imageSizeFromCacheForURL:(NSURL *)url;

/**
 *  Store an imageSize into memory and disk cache
 *
 *  @param image          image
 *  @param url            imageURL
 *  @param completedBlock An block that should be executed after the imageSize has been saved (optional)
 */
+(void)storeImageSize:(UIImage *)image forURL:(NSURL *)url completed:(nullable LYHImageAutoSizeCacheCompletionBlock)completedBlock;

/**
 *  Get reload state from cache,query the disk cache synchronously after checking the memory cache
 *
 *  @param url imageURL
 *
 *  @return reloadState
 */
+(BOOL)reloadStateFromCacheForURL:(NSURL *)url;

/**
 *  Store an reloadState into memory and disk cache
 *
 *  @param state          reloadState
 *  @param url            imageURL
 *  @param completedBlock An block that should be executed after the reloadState has been saved (optional)
 */
+(void)storeReloadState:(BOOL)state forURL:(NSURL *)url completed:(nullable LYHImageAutoSizeCacheCompletionBlock)completedBlock;

@end
NS_ASSUME_NONNULL_END

