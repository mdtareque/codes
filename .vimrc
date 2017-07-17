" https://github.com/tpope/vim-pathogen To install vim plugins
execute pathogen#infect()
syntax on
filetype plugin indent on

" https://github.com/godlygeek/tabular vim plugin to align
inoremap <silent> <Bar>   <Bar><Esc>:call <SID>align()<CR>a
function! s:align()
  let p = '^\s*|\s.*\s|\s*$'
  if exists(':Tabularize') && getline('.') =~# '^\s*|' && (getline(line('.')-1) =~# p || getline(line('.')+1) =~# p)
    let column = strlen(substitute(getline('.')[0:col('.')],'[^|]','','g'))
    let position = strlen(matchstr(getline('.')[0:col('.')],'.*|\s*\zs.*'))
    Tabularize/|/l1
    normal! 0
    call search(repeat('[^|]*|',column).'\s\{-\}'.repeat('.',position),'ce',line('.'))
  endif
endfunction

" only to work in insert mode
iabb main #include<stdio.h><CR>
            \#include<string.h><CR>
            \<CR>
            \int main(int argc, char *argv[]) {<CR>
            \int t, n;<CR>
            \scanf("%d", &t);<CR>
            \while(t--) {<CR>
            \scanf("%d", &n);<CR>
            \}<CR>
            \return 0;<CR>
            \}<CR><ESC>i
iabb sm #include<stdio.h><CR>
\<CR>
\int main() {<CR>
\    <CR>
\return 0;<CR>
\}<Esc>kkllli


iab ic #include
iab pf printf("");<Esc>hhi
iab pfn printf("\n");
iab pfd printf("%d",);<Esc>hhhi
iab pfs printf("%s\n",);<Esc>hhhi
iab sf scanf("%", &);<Esc>hhhi
iab sfd scanf("%d", &);<Esc>hhhi
iab sfs scanf("%s", &);<Esc>hhhi
iab fori for(i=0; i<n; i++)
iab forj for(j=0; j<n; j++)
iab wi while(i<n)


" autocomplete xml/html end tag
:iabbrev </ </<C-X><C-O>
iab html5 <!DOCTYPE html><CR>
            \<html><head><meta charset="utf-8"><title>Page title</title></head><CR>
            \<body><CR>
            \<h1></h1><CR>
            \<div><p>Content</p></div><CR>
            \</body></html>


"iab fgets
"iab ct Computational Thinking

" strip trailing space on save
autocmd BufWritePre * :%s/\s\+$//e

" auto-indent, expand-tab, shift-width, tab-stop
set et
set sw=4
set ts=4

" display status line 'laststatus'
" set ls=2
set ai

colorscheme desert

"set spell

" save and load folds
autocmd BufWinLeave *.* mkview
autocmd BufWinEnter *.* silent loadview

" Syntastic
"set statusline+=%#warningmsg#
"set statusline+=%{SyntasticStatuslineFlag()}
"set statusline+=%*
"
"let g:syntastic_always_populate_loc_list = 1
"let g:syntastic_auto_loc_list = 1
"let g:syntastic_check_on_open = 1
"let g:syntastic_check_on_wq = 0
"
let g:syntastic_mode_map = { 'mode': 'passive', 'active_filetypes': [],'passive_filetypes': [] }
nnoremap <C-w>E :SyntasticCheck<CR> :SyntasticToggleMode<CR>

" set cursorline  " displays horizontal line
set laststatus=2  " Always show status line
set nostartofline
set ruler
set ignorecase
" display invisible characters
set list
set lcs=tab:▸\ ,trail:·,eol:¬,nbsp:_


" reopening a file with cursor set to previous position
if has("autocmd")
  au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif
