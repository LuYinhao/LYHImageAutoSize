# LYHImageAutoSize

[![CI Status](https://img.shields.io/travis/Lucas/LYHImageAutoSize.svg?style=flat)](https://travis-ci.org/Lucas/LYHImageAutoSize)
[![Version](https://img.shields.io/cocoapods/v/LYHImageAutoSize.svg?style=flat)](https://cocoapods.org/pods/LYHImageAutoSize)
[![License](https://img.shields.io/cocoapods/l/LYHImageAutoSize.svg?style=flat)](https://cocoapods.org/pods/LYHImageAutoSize)
[![Platform](https://img.shields.io/cocoapods/p/LYHImageAutoSize.svg?style=flat)](https://cocoapods.org/pods/LYHImageAutoSize)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

## Installation

LYHImageAutoSize is available through [CocoaPods](https://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'LYHImageAutoSize'
```

```objective-c
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath{
    NSString *url = self.dataArray[indexPath.row];
    /**
     *  参数1:图片URL
     *  参数2:imageView 宽度
     *  参数3:预估高度(此高度仅在图片尚未加载出来前起作用,不影响真实高度)
     */
    return [LYHImageAutoSize imageHeightForURL:[NSURL URLWithString:url] layoutWidth:[UIScreen mainScreen].bounds.size.width-16 estimateHeight:200];
}   

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{
    DemoVC1Cell *cell = [tableView dequeueReusableCellWithIdentifier:cellId];
    if(!cell){
        cell = [[DemoVC1Cell alloc]initWithStyle:UITableViewCellStyleDefault reuseIdentifier:cellId];
    }
    NSString *url = self.dataArray[indexPath.row];
    //加载网络图片使用SDWebImage
    [cell.imgView sd_setImageWithURL:[NSURL URLWithString:url] completed:^(UIImage *image, NSError *error, SDImageCacheType cacheType, NSURL *imageURL) {
        /** 缓存image size */
        [LYHImageAutoSize storeImageSize:image forURL:imageURL completed:^(BOOL result) {
            /** reload  */
            if(result)  [tableView  lyh_reloadDataForURL:imageURL];
        }];
    }];
    return cell;
}
```

## API

- 1.获取图片高度/尺寸及缓存相关

```
/**
 *   Get image height
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
+(void)storeImageSize:(UIImage *)image forURL:(NSURL *)url completed:(LYHImageAutoSizeCacheCompletionBlock)completedBlock;
```

- 2.tableView reload

```
/**
 Reload tableView

 @param url imageURL
 */
-(void)lyh_reloadDataForURL:(NSURL *)url;
```

- 3.collectionView reload

```objective-c
/**
 Reload collectionView
 
 @param url imageURL
 */
-(void)lyh_reloadDataForURL:(NSURL *)url;
```

## Author

Lucas, 29539153@qq.com

## License

LYHImageAutoSize is available under the MIT license. See the LICENSE file for more info.

