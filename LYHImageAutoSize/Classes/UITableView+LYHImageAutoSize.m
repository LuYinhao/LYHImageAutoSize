//
//  UITableView+LYHImageAutoSize.m
//  LYHImageAutoSizeExample
//
//  Created by Lucas on 09/28/2020.
//  Copyright (c) 2020 Lucas. All rights reserved.
//  http://git.swste.com/lucas/LYHImageAutoSize

#import "UITableView+LYHImageAutoSize.h"
#import "LYHImageAutoSizeConst.h"
#import "LYHImageAutoSize.h"

@implementation UITableView (LYHImageAutoSize)

-(void)lyh_reloadDataForURL:(NSURL *)url{
    BOOL reloadState = [LYHImageAutoSize reloadStateFromCacheForURL:url];
    if(!reloadState){
        [self reloadData];
        [LYHImageAutoSize storeReloadState:YES forURL:url completed:nil];
    }
}


@end
