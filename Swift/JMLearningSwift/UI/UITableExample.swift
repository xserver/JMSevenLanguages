//
//  UITableExample.swift
//  JMLearningSwift
//
//  Created by xserver on 15/4/29.
//  Copyright (c) 2015年 https://github.com/xserver. All rights reserved.
//

import UIKit

@objc(UITableExample)   //  NSClassFromString 

class UITableExample: UIViewController {

    var list:NSArray = []
    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.backgroundColor = UIColor.whiteColor()
        
        
        ObjectLife()
        ObjectLife("haha")
        ObjectLife(objectName: "haha2")

    }
    
    
    //MARK: -
    //MARK: UITableViewDataSource
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return list.count;
    }
    
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        
        var cell = tableView.cellForRowAtIndexPath(indexPath)
        
        if cell == nil {
            cell = UITableViewCell(style: UITableViewCellStyle.Default, reuseIdentifier: "test")
        }
        
//        cell?.textLabel?.text = list[indexPath.row]
        
        return cell!
    }
    
    // MARK: -
    // MARK: UITableViewDelegate
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
    }

}
