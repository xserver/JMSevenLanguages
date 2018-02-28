//
//  CatalogCtrl.swift
//  JMLearningSwift
//
//  Created by xserver on 15/4/28.
//  Copyright (c) 2015年 https://github.com/xserver. All rights reserved.
//

import UIKit

class CatalogCtrl: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    var list = ["A", "B"]   //?
    var tab: UITableView!
    
    lazy var myfruit = Apple(name: "My Apple.")

    var haha: NSString {
        //
        return "catalog haha"
    }
    
//MARK: -
//MARK: viewDidLoad
    override func viewDidLoad() {
        super.viewDidLoad()

        self.view.backgroundColor = UIColor.purpleColor()
        list = ["UITableExample", "B"]
        
        self.addViews();
        
//        self.myfruit.say()
        print(self.haha)
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func addViews() {
        tab = UITableView(frame: self.view.bounds, style: UITableViewStyle.Plain)
        tab.dataSource = self
        tab.delegate = self
        self.view.addSubview(self.tab)
    }
    func loadData() {
    
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
        
        cell?.textLabel?.text = list[indexPath.row]

        return cell!
    }
    
// MARK: -
// MARK: UITableViewDelegate
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        

        let name = self.list[indexPath.row]


//        var ctrl: UIViewController = NSClassFromString(name).new() as? UIViewController
        
        if let theClass = NSClassFromString(name) as? UIViewController.Type {
            let ctrl = theClass.init(nibName: nil, bundle: nil)
            self.navigationController?.pushViewController(ctrl, animated: true)
        }
    }

}





