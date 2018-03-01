//
//  ViewController.swift
//  JMLearningSwift4
//
//  Created by Macro on 2018/3/1.
//  Copyright © 2018年 Macro. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {

    var list = ["A", "B"]   //?
    var tab: UITableView!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.view.backgroundColor = UIColor.purple
        list = ["A", "B"]
        
        self.addViews();
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    func addViews() {
        tab = UITableView(frame: self.view.bounds, style: UITableViewStyle.plain)
        tab.dataSource = self
        tab.delegate = self
        self.view.addSubview(self.tab)
    }

    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return list.count;
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        var cell = tableView.cellForRow(at: indexPath as IndexPath)
        
        if cell == nil {
            cell = UITableViewCell(style: UITableViewCellStyle.default, reuseIdentifier: "test")
        }
        
        cell?.textLabel?.text = list[indexPath.row]
        
        return cell!
    }

}

