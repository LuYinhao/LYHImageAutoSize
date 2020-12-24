//
//  NewsModel.h
//  LYHImageAutoSizeExample
//
//  Created by Lucas on 09/28/2020.
//  Copyright (c) 2020 Lucas. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NewsModel : NSObject

@property (nonatomic, copy) NSString *title;

@property (nonatomic, copy) NSString *source;

@property (nonatomic, copy) NSString *digest;

@property (nonatomic, copy) NSString *top_image;

@property (nonatomic, copy) NSString *content;

@property (nonatomic, copy) NSString *text_image0;

@property (nonatomic, assign) NSInteger reply_count;

@property (nonatomic, copy) NSString *news_id;

@property (nonatomic, copy) NSString *edit_time;

@property (nonatomic, copy) NSString *text_image1;

@end
