//
//  WaterfallColectionLayout.h
//  LYHImageAutoSizeExample
//
//  Created by Lucas on 09/28/2020.
//  Copyright (c) 2020 Lucas. All rights reserved.
//

#import <UIKit/UIKit.h>



typedef  CGFloat(^itemHeightBlock)(NSIndexPath* index);
@interface WaterfallColectionLayout : UICollectionViewLayout

@property(nonatomic,strong )itemHeightBlock heightBlock ;
@property(nonatomic,assign,readonly) CGFloat itemWidth;

-(instancetype)initWithItemsHeightBlock:(itemHeightBlock)block;

@end
