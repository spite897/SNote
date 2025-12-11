# Plog
- program: **gitbeginner** 
- status: **done** 
  
-----------------------------------------------------------------------------

#### cheatbox

| name                                   | desc                     |
| --                                     | --                       |
| **basis**                              | **--**                   |
| `init`                                 | 初始化倉庫               |
| `add <file/dir>`                       | 追蹤文件                 |
| `diff`                                 | 查看追蹤文件變化         |
| `reset <file/dir>`                     | 取消追蹤                 |
| `config --global user.name <text>`     | --                       |
| `config --global user.email <text>`    | --                       |
| `config --global core.editor <editor>` | --                       |
| `commit -m <text>`                     | 提交名爲< > 的更改       |
| `commit`                               | 提交並進入編輯更改信息   |
| `rm --cached <file>`                   | 刪除版本庫的文件         |
| **branch**                             | **--**                   |
| `branch <branchname>`                  | 創建分支                 |
| `branch -d <branchname>`               | 刪除分支                 |
| `branch`                               | 查看分支                 |
| `checkout <branchname>`                | 切換分支                 |
| `merge <branchname>`                   | 合並分支                 |
| **remote**                             | **--**                   |
| `remote add origin <repo>`             | 設置倉庫                 |
| `push`                                 | 上傳                     |
| `pull`                                 | 下載                     |
 
> git_merge_tool
 
`/.git.ignore`
忽略文件列表

> `git config credential.helper store`
> 保存賬戶密碼

- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#### addtion : 關於鏈接github

是時，github進行push時不再需要密碼，而是token

在github網站登錄後，在個人設置中可以生成token

![github_token_generation](/imgs/TheCW/251029_gitbeginner.png)

> 注意Permission的選擇，要給予讀寫權利
 
-----------------------------------------------------------------------------
