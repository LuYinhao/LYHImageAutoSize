//
//  UICollectionView+LYHImageAutoSize.h
//  LYHImageAutoSizeExample
//
//  Created by Lucas on 09/28/2020.
//  Copyright (c) 2020 Lucas. All rights reserved.
//  http://git.swste.com/lucas/LYHImageAutoSize

#import <UIKit/UIKit.h>
#import "LYHImageAutoSizeConst.h"

@interface UICollectionView (LYHImageAutoSize)

/**
 Reload collectionView
 
 @param url imageURL
 */
-(void)lyh_reloadDataForURL:(NSURL *)url;

@end
