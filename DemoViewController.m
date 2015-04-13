//
//  DemoViewController.m
//  文档
//
//  Created by guohui on 15/4/11.
//  Copyright (c) 2015年 youyibao. All rights reserved.
//

#import "DemoViewController.h"

@interface DemoViewController ()<UISearchBarDelegate>
{
    UISearchBar *_searchBar;
}
@end

@implementation DemoViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor cyanColor];
    // Do any additional setup after loading the view, typically from a nib.
    
    _searchBar = [[UISearchBar alloc]initWithFrame:CGRectMake(20, 60, 280, 30)];
    _searchBar.delegate = self;
    _searchBar.placeholder = @"名称／编码／助记号";
    _searchBar.showsBookmarkButton = YES;//这个用来显示图书标志的
    _searchBar.showsCancelButton = YES; //取消按钮
    [self.view addSubview:_searchBar];
    
    //    //修改搜索框背景
    //    _searchBar.backgroundColor=[UIColor redColor];
    
    //3自定义背景
    //    UIImageView *imageView = [[UIImageView alloc] initWithImage:[UIImage imageNamed:@"QQ20150411-1@2x.png"]];
    UIImageView *imageView = [[UIImageView alloc]init];
    imageView.backgroundColor = [UIColor cyanColor];
    imageView.frame = CGRectMake(0, 0, 280, 30);
    [_searchBar insertSubview:imageView atIndex:1];
}
//取消
- (void)searchBarCancelButtonClicked:(UISearchBar *)searchBar{
    [searchBar resignFirstResponder];
}
//book
- (void)searchBarBookmarkButtonClicked:(UISearchBar *)searchBar{
    //可以进行语音识别
    [searchBar resignFirstResponder];
}
//搜索
- (void)searchBarSearchButtonClicked:(UISearchBar *)searchBar{
    [searchBar resignFirstResponder];
    NSLog(@"搜索按钮被点击了");
    
}
- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
