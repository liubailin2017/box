#include "SDLC_Tooltip.h"
#include<vector>


SDLC_Tooltip::SDLC_Tooltip(SDLC_Context *context):SDLC_WLabel(context,16,L""),div_height(3) {
}

void SDLC_Tooltip::show(std::wstring msg) {

}

void SDLC_Tooltip::clear_surface() {
    SDL_Surface *tmp_surface;    
    for(int i = 0; i< texts.size(); i++) {
        tmp_surface = texts[i];
        if(tmp_surface) {
            SDL_FreeSurface(tmp_surface);
            tmp_surface = NULL;
        }
    }
    texts.clear();
}

void SDLC_Tooltip::updateSurface() {
    SDLC_Component::updateSurface();
    SDL_Surface *tmp_surface;    
    SDL_Rect dest = {0,0,0,0};
    for(int i = 0; i< texts.size(); i++) {
        tmp_surface = texts[i];
        dest.w = tmp_surface->w;
        dest.h = tmp_surface->h;
        SDL_BlitSurface(tmp_surface,NULL,surface,&dest);
        dest.y += tmp_surface->h + div_height;
    }
}

void SDLC_Tooltip::setText(std::wstring text) {
    SDL_Color color = {text_color&0xff,text_color>>8 & 0xff ,text_color >> 16 & 0xff};
    
    SDL_Surface *tmp_surface;    
    clear_surface();
    
    std::vector<std::wstring> lines;
    size_t pos = 0;
    size_t len = text.length();
    std::wstring delim = L"\n";
    size_t delim_len = delim.length();
    while (pos < len)
    {
        int find_pos = text.find(delim, pos);
        if (find_pos < 0)
        {
            lines.push_back(text.substr(pos, len - pos));
            break;
        }
        lines.push_back(text.substr(pos, find_pos - pos));
        pos = find_pos + delim_len;
    }

    int h = 0;
    int w = 0;
    for(int i = 0; i < lines.size(); i++) {
        tmp_surface = TTF_RenderUNICODE_Solid(ttf,(Uint16*)lines[i].c_str(),color);
        /* 高不断加高，宽取最宽的一个 */
        h += (tmp_surface->h + div_height);
        if(tmp_surface->w > w) {
            w = tmp_surface->w;
        }
        texts.push_back(tmp_surface);
    }
    if( h > div_height){ /* 减去最后多一个间距 */
        h -= div_height;
    }
    
    setSize(w,h);
}

SDLC_Tooltip::~SDLC_Tooltip() {
    clear_surface();
}

