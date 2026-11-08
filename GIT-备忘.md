# Git 常用命令备忘

个人速查表，针对本仓库（`c-learning`）的日常操作。忘了就翻这一页。

## 日常四步

```
1. git status              看有哪些改动
2. git add -A              全部加入暂存区
3. git commit -m "说明"     提交到本地
4. git push                推送到 GitHub
```

`commit` 只是存到本地，`push` 才会上传到 GitHub。**少第 4 步，GitHub 上什么都不会变。**

## 命令表

| 目的 | 命令 |
| --- | --- |
| 查看当前状态 | `git status` |
| 查看具体改了哪几行 | `git diff` |
| 全部加入暂存 | `git add -A` |
| 只加单个文件 | `git add day17/day17_exercise.c` |
| 提交并附说明 | `git commit -m "feat: 新增字符串逆序练习"` |
| 推送到远程 | `git push` |
| 查看提交历史（简版） | `git log --oneline -10` |
| 撤销未提交的修改 | `git restore 文件名` |
| 撤销已暂存但未提交 | `git restore --staged 文件名` |
| 拉取远程更新 | `git pull` |
| 查看远程地址 | `git remote -v` |

## 提交说明前缀

| 前缀 | 使用场景 |
| --- | --- |
| `feat:` | 新增功能、新的练习 |
| `fix:` | 修复问题 |
| `docs:` | 只改文档或笔记 |
| `refactor:` | 重构，不改变功能 |
| `chore:` | 杂项，如配置、忽略规则 |

示例：`feat(day18): 新增字符分类统计练习`

## 常见问题

**提交后 GitHub 上没变化**
忘了 `git push`。`commit` 和 `push` 是两件事。

**提示 `Everything up-to-date`**
没有新提交，通常是因为只 `add` 了没 `commit`。

**提示 `Author identity unknown`**
没配置用户名邮箱，执行一次即可：

```bash
git config --global user.name "len536"
git config --global user.email "你的邮箱"
```

**`commit` 后卡在一个黑屏界面里**
说明 `-m` 后面的说明忘了写，进入了 vim 编辑器。按 `Esc`，输入 `:wq` 回车即可退出。

**推送被拒绝（`rejected ... fetch first`）**
远程有你本地没有的提交，先 `git pull` 再 `git push`。

**改坏了想回到上次提交的状态**
`git restore 文件名`（只影响未提交的改动，已提交的内容不会丢）。

## 本仓库的远程配置

走 SSH，不需要输密码：

```bash
git remote -v
# origin  git@github.com:len536/c-learning.git
```

如果误改成了 HTTPS 导致超时，用这条改回来：

```bash
git remote set-url origin git@github.com:len536/c-learning.git
```

## 建议的提交节奏

- 每写完一个练习就提交一次，不要攒
- 提交说明写清楚"做了什么"，不写"update""修改"这种
- 每天结束前 `git push` 一次，保证代码在云端有备份
