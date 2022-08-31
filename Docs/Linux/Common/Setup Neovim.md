Plugins with Vim-Plug

sudo apt install neovim

mkdir ~/.config/nvim

touch ~/.config/nvim/init.vim

curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim

mkdir ~/.config/nvim/vim-plug

touch ~/.config/nvim/vim-plug/plugins.vim

- Add the following to ~/.config/nvim/vim-plug/plugins.vim

" auto-install vim-plug
if empty(glob('~/.config/nvim/autoload/plug.vim'))
  silent !curl -fLo ~/.config/nvim/autoload/plug.vim --create-dirs
    \ https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
  "autocmd VimEnter * PlugInstall
  "autocmd VimEnter * PlugInstall | source $MYVIMRC
endif

call plug#begin('~/.config/nvim/autoload/plugged')

    " Better Syntax Support
    Plug 'sheerun/vim-polyglot'
    " File Explorer
    Plug 'scrooloose/NERDTree'
    " Auto pairs for '(' '[' '{'
    Plug 'jiangmiao/auto-pairs'

call plug#end()

- Add the following line to init.vim

source $HOME/.config/nvim/vim-plug/plugins.vim

- Vim-plug commands

- Open nvim
nvim

- Check the status of your plugins
:PlugStatus

- Install all of your plugins
:PlugInstall

- To update your plugins
:PlugUpdate

- After the update you can press d to see the differences or run
:PlugDiff

- To remove plugins that are no longer defined in the plugins.vim file
:PlugClean

- Finally if you want to upgrade vim-plug itself run the following
:PlugUpgrade
