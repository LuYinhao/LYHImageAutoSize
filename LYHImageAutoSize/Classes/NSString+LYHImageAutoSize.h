//
//  NSString+LYHImageAutoSize.h
//  LYHImageAutoSizeExample
//
//  Created by Lucas on 09/28/2020.
//  Copyright (c) 2020 Lucas. All rights reserved.
//  http://git.swste.com/lucas/LYHImageAutoSize

#import <Foundation/Foundation.h>

@interface NSString (LYHImageAutoSize)
@property(nonatomic,copy ,readonly)NSString * sizeKeyName;
@property(nonatomic,copy ,readonly)NSString * reloadKeyName;
@property(nonatomic,copy ,readonly)NSString * md5String;
@end
