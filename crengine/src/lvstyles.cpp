/*******************************************************

   CoolReader Engine

   lvstyles.cpp:  CSS styles hash

   (c) Vadim Lopatin, 2000-2006
   This source code is distributed under the terms of
   GNU General Public License
   See LICENSE file for details

*******************************************************/

#include "../include/lvstyles.h"

// #include <stdio.h>

//DEFINE_NULL_REF( css_style_rec_t )

/// calculate font instance record hash
lUInt32 calcHash(font_ref_t & f)
{
    if ( !f )
        return 14321;
    if ( f->_hash )
        return f->_hash;
    lUInt32 v = 31;
    v = v * 31 + (lUInt32)f->getFontFamily();
    v = v * 31 + (lUInt32)f->getSize();
    v = v * 31 + (lUInt32)f->getWeight();
    v = v * 31 + (lUInt32)f->getItalic();
    v = v * 31 + (lUInt32)f->getFeatures();
    v = v * 31 + (lUInt32)f->getKerningMode();
    // No more needed since hinting mode does not change advances
    // v = v * 31 + (lUInt32)f->getHintingMode();
    v = v * 31 + (lUInt32)f->getBitmapMode();
    v = v * 31 + (lUInt32)f->getTypeFace().getHash();
    v = v * 31 + (lUInt32)f->getBaseline();
    f->_hash = v;
    return v;
}


lUInt32 calcHash(css_style_rec_t & rec)
{
    if ( !rec.hash )
        rec.hash = ((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((((
         + (lUInt32)rec.important[0]) * 31
         + (lUInt32)rec.important[1]) * 31
         + (lUInt32)rec.important[2]) * 31
         + (lUInt32)rec.importance[0]) * 31
         + (lUInt32)rec.importance[1]) * 31
         + (lUInt32)rec.importance[2]) * 31
         + (lUInt32)rec.display) * 31
         + (lUInt32)rec.white_space) * 31
         + (lUInt32)rec.text_align) * 31
         + (lUInt32)rec.text_align_last) * 31
         + (lUInt32)rec.text_decoration) * 31
         + (lUInt32)rec.text_transform) * 31
         + (lUInt32)rec.hyphenate) * 31
         + (lUInt32)rec.list_style_type) * 31
         + (lUInt32)rec.letter_spacing.pack()) * 31
         + (lUInt32)rec.list_style_position) * 31
         + (lUInt32)(rec.page_break_before | (rec.page_break_after<<4) | (rec.page_break_inside<<8))) * 31
         + (lUInt32)rec.vertical_align.pack()) * 31
         + (lUInt32)rec.font_size.type) * 31
         + (lUInt32)rec.font_size.value) * 31
         + (lUInt32)rec.font_style) * 31
         + (lUInt32)rec.font_weight) * 31
         + (lUInt32)rec.font_features.pack()) * 31
         + (lUInt32)rec.line_height.pack()) * 31
         + (lUInt32)rec.color.pack()) * 31
         + (lUInt32)rec.background_color.pack()) * 31
         + (lUInt32)rec.width.pack()) * 31
         + (lUInt32)rec.height.pack()) * 31
         + (lUInt32)rec.min_width.pack()) * 31
         + (lUInt32)rec.min_height.pack()) * 31
         + (lUInt32)rec.max_width.pack()) * 31
         + (lUInt32)rec.max_height.pack()) * 31
         + (lUInt32)rec.text_indent.pack()) * 31
         + (lUInt32)rec.margin[0].pack()) * 31
         + (lUInt32)rec.margin[1].pack()) * 31
         + (lUInt32)rec.margin[2].pack()) * 31
         + (lUInt32)rec.margin[3].pack()) * 31
         + (lUInt32)rec.padding[0].pack()) * 31
         + (lUInt32)rec.padding[1].pack()) * 31
         + (lUInt32)rec.padding[2].pack()) * 31
         + (lUInt32)rec.padding[3].pack()) * 31
         + (lUInt32)rec.border_style_top) * 31
         + (lUInt32)rec.border_style_right) * 31
         + (lUInt32)rec.border_style_bottom) * 31
         + (lUInt32)rec.border_style_left) * 31
         + (lUInt32)rec.border_width[0].pack()) * 31
         + (lUInt32)rec.border_width[1].pack()) * 31
         + (lUInt32)rec.border_width[2].pack()) * 31
         + (lUInt32)rec.border_width[3].pack()) * 31
         + (lUInt32)rec.border_color[0].pack()) * 31
         + (lUInt32)rec.border_color[1].pack()) * 31
         + (lUInt32)rec.border_color[2].pack()) * 31
         + (lUInt32)rec.border_color[3].pack()) * 31
         + (lUInt32)rec.background_repeat)*31
         + (lUInt32)rec.background_position)*31
         + (lUInt32)rec.background_size[0].pack())*31
         + (lUInt32)rec.background_size[1].pack())*31
         + (lUInt32)rec.font_family) * 31
         + (lUInt32)rec.border_collapse)*31
         + (lUInt32)rec.border_spacing[0].pack())*31
         + (lUInt32)rec.border_spacing[1].pack())*31
         + (lUInt32)rec.orphans) * 31
         + (lUInt32)rec.widows) * 31
         + (lUInt32)rec.float_) * 31
         + (lUInt32)rec.clear) * 31
         + (lUInt32)rec.direction) * 31
         + (lUInt32)rec.visibility) * 31
         + (lUInt32)rec.line_break) * 31
         + (lUInt32)rec.word_break) * 31
         + (lUInt32)rec.box_sizing) * 31
         + (lUInt32)rec.cr_hint.pack()) * 31
         + (lUInt32)rec.font_name.getHash()
         + (lUInt32)rec.background_image.getHash()
         + (lUInt32)rec.content.getHash());
    return rec.hash;
}

bool operator == (const css_style_rec_t & r1, const css_style_rec_t & r2)
{
    return 
           r1.important[0] == r2.important[0] &&
           r1.important[1] == r2.important[1] &&
           r1.important[2] == r2.important[2] &&
           r1.importance[0] == r2.importance[0] &&
           r1.importance[1] == r2.importance[1] &&
           r1.importance[2] == r2.importance[2] &&
           r1.display == r2.display &&
           r1.white_space == r2.white_space &&
           r1.text_align == r2.text_align &&
           r1.text_align_last == r2.text_align_last &&
           r1.text_decoration == r2.text_decoration &&
           r1.text_transform == r2.text_transform &&
           r1.list_style_type == r2.list_style_type &&
           r1.list_style_position == r2.list_style_position &&
           r1.hyphenate == r2.hyphenate &&
           r1.vertical_align == r2.vertical_align &&
           r1.line_height == r2.line_height &&
           r1.width == r2.width &&
           r1.height == r2.height &&
           r1.min_width == r2.min_width &&
           r1.min_height == r2.min_height &&
           r1.max_width == r2.max_width &&
           r1.max_height == r2.max_height &&
           r1.color == r2.color &&
           r1.background_color == r2.background_color &&
           r1.text_indent == r2.text_indent &&
           r1.margin[0] == r2.margin[0] &&
           r1.margin[1] == r2.margin[1] &&
           r1.margin[2] == r2.margin[2] &&
           r1.margin[3] == r2.margin[3] &&
           r1.padding[0] == r2.padding[0] &&
           r1.padding[1] == r2.padding[1] &&
           r1.padding[2] == r2.padding[2] &&
           r1.padding[3] == r2.padding[3] &&
           r1.font_size.type == r2.font_size.type &&
           r1.font_size.value == r2.font_size.value &&
           r1.font_style == r2.font_style &&
           r1.font_weight == r2.font_weight &&
           r1.font_name == r2.font_name &&
           r1.font_family == r2.font_family&&
           r1.font_features == r2.font_features&&
           r1.border_style_top==r2.border_style_top&&
           r1.border_style_right==r2.border_style_right&&
           r1.border_style_bottom==r2.border_style_bottom&&
           r1.border_style_left==r2.border_style_left&&
           r1.border_width[0]==r2.border_width[0]&&
           r1.border_width[1]==r2.border_width[1]&&
           r1.border_width[2]==r2.border_width[2]&&
           r1.border_width[3]==r2.border_width[3]&&
           r1.border_color[0]==r2.border_color[0]&&
           r1.border_color[1]==r2.border_color[1]&&
           r1.border_color[2]==r2.border_color[2]&&
           r1.border_color[3]==r2.border_color[3]&&
           r1.background_image==r2.background_image&&
           r1.background_repeat==r2.background_repeat&&
           r1.background_position==r2.background_position&&
           r1.background_size[0]==r2.background_size[0]&&
           r1.background_size[1]==r2.background_size[1]&&
           r1.border_collapse==r2.border_collapse&&
           r1.border_spacing[0]==r2.border_spacing[0]&&
           r1.border_spacing[1]==r2.border_spacing[1]&&
           r1.orphans==r2.orphans&&
           r1.widows==r2.widows&&
           r1.float_ == r2.float_&&
           r1.clear == r2.clear&&
           r1.direction == r2.direction&&
           r1.visibility == r2.visibility&&
           r1.line_break == r2.line_break&&
           r1.word_break == r2.word_break&&
           r1.box_sizing == r2.box_sizing&&
           r1.content == r2.content&&
           r1.cr_hint==r2.cr_hint;
}


/// splits string like "Arial", Times New Roman, Courier;  into list
// returns number of characters processed
int splitPropertyValueList( const char * str, lString8Collection & list )
{
    //
    int i=0;
    lChar8 quote_char = 0;
    lString8 name;
    name.reserve(32);
    bool last_space = false;
    for (i=0; str[i]; i++)
    {
        switch(str[i])
        {
        case '\'':
        case '\"':
            {
                if (quote_char==0)
                {
                    if (!name.empty())
                    {
                        list.add( name );
                        name.clear();
                    }
                    quote_char = str[i];
                }
                else if (quote_char==str[i])
                {
                    if (!name.empty())
                    {
                        list.add( name );
                        name.clear();
                    }
                    quote_char = 0;
                }
                else
                {
                    // append char
                    name << str[i];
                }
                last_space = false;
            }
            break;
        case ',':
            {
                if (quote_char==0)
                {
                    if (!name.empty())
                    {
                        list.add( name );
                        name.clear();
                    }
                }
                else
                {
                    // inside quotation: append char
                    name << str[i];
                }
                last_space = false;
            }
            break;
        case '\t':
        case ' ':
            {
                if (quote_char!=0)
                {
                    name << str[i];
                }
                last_space = true;
            }
            break;
        case ';':
        case '}':
                if (quote_char==0)
                {
                    if (!name.empty())
                    {
                        list.add( name );
                        name.clear();
                    }
                    return i;
                }
                else
                {
                    // inside quotation: append char
                    name << str[i];
                    last_space = false;
                }
            break;
        default:
            if (last_space && !name.empty() && quote_char==0)
                name << ' ';
            name += str[i];
            last_space = false;
            break;
        }
    }
    if (!name.empty())
    {
        list.add( name );
    }
    return i;
}

/// splits string like "Arial", Times New Roman, Courier  into list
lString8 joinPropertyValueList( const lString8Collection & list )
{
    lString8 res;
    res.reserve(100);
    
    for (int i=0; i<list.length(); i++)
    {
        if (i>0)
            res << ", ";
        res << "\"" << list[i] << "\"";
    }
    
    res.pack();
    return res;
}

static const char * style_magic = "CR3STYLE";
#define ST_PUT_ENUM(v) buf << (lUInt8)v
#define ST_GET_ENUM(t,v) { lUInt8 tmp; buf >> tmp; v=(t)tmp; if (buf.error()) return false; }
#define ST_PUT_LEN(v) buf << (lUInt8)v.type << (lInt32)v.value;
#define ST_GET_LEN(v) { lUInt8 t; buf >> t; lInt32 val; buf >> val; v.type = (css_value_type_t)t; v.value = val; if (buf.error()) return false; }
#define ST_PUT_LEN4(v) ST_PUT_LEN(v[0]);ST_PUT_LEN(v[1]);ST_PUT_LEN(v[2]);ST_PUT_LEN(v[3]);
#define ST_GET_LEN4(v) ST_GET_LEN(v[0]);ST_GET_LEN(v[1]);ST_GET_LEN(v[2]);ST_GET_LEN(v[3]);
#define ST_PUT_UI64(v) buf << (lUInt32)(v>>32) << (lUInt32)(v&0xFFFFFFFFULL)
#define ST_GET_UI64(v) { lUInt32 t; buf >> t; v = (lUInt64)(t)<<32; buf >> t; v += t; if (buf.error()) return false; }
bool css_style_rec_t::serialize( SerialBuf & buf )
{
    if ( buf.error() )
        return false;
    buf.putMagic(style_magic);
    buf << important[0];            //    lUInt32              important[0];
    buf << important[1];            //    lUInt32              important[1];
    buf << important[2];            //    lUInt32              important[2];
    buf << importance[0];           //    lUInt32              importance[0];
    buf << importance[1];           //    lUInt32              importance[1];
    buf << importance[2];           //    lUInt32              importance[2];
    ST_PUT_ENUM(display);           //    css_display_t        display;
    ST_PUT_ENUM(white_space);       //    css_white_space_t    white_space;
    ST_PUT_ENUM(text_align);        //    css_text_align_t     text_align;
    ST_PUT_ENUM(text_align_last);   //    css_text_align_t     text_align_last;
    ST_PUT_ENUM(text_decoration);   //    css_text_decoration_t text_decoration;
    ST_PUT_ENUM(text_transform);    //    css_text_transform_t text_transform;
    ST_PUT_LEN(vertical_align);     //    css_length_t         vertical_align;
    ST_PUT_ENUM(font_family);       //    css_font_family_t    font_family;
    buf << font_name;               //    lString8             font_name;
    ST_PUT_LEN(font_size);          //    css_length_t         font_size;
    ST_PUT_ENUM(font_style);        //    css_font_style_t     font_style;
    ST_PUT_ENUM(font_weight);       //    css_font_weight_t    font_weight;
    ST_PUT_LEN(font_features);      //    css_length_t         font_features;
    ST_PUT_LEN(text_indent);        //    css_length_t         text_indent;
    ST_PUT_LEN(line_height);        //    css_length_t         line_height;
    ST_PUT_LEN(width);              //    css_length_t         width;
    ST_PUT_LEN(height);             //    css_length_t         height;
    ST_PUT_LEN(min_width);          //    css_length_t         min_width;
    ST_PUT_LEN(min_height);         //    css_length_t         min_height;
    ST_PUT_LEN(max_width);          //    css_length_t         max_width;
    ST_PUT_LEN(max_height);         //    css_length_t         max_height;
    ST_PUT_LEN4(margin);            //    css_length_t         margin[4]; ///< margin-left, -right, -top, -bottom
    ST_PUT_LEN4(padding);           //    css_length_t         padding[4]; ///< padding-left, -right, -top, -bottom
    ST_PUT_LEN(color);              //    css_length_t         color;
    ST_PUT_LEN(background_color);   //    css_length_t         background_color;
    ST_PUT_LEN(letter_spacing);     //    css_length_t         letter_spacing;
    ST_PUT_ENUM(page_break_before); //    css_page_break_t     page_break_before;
    ST_PUT_ENUM(page_break_after);  //    css_page_break_t     page_break_after;
    ST_PUT_ENUM(page_break_inside); //    css_page_break_t     page_break_inside;
    ST_PUT_ENUM(hyphenate);         //    css_hyphenate_t      hyphenate;
    ST_PUT_ENUM(list_style_type);   //    css_list_style_type_t list_style_type;
    ST_PUT_ENUM(list_style_position);//    css_list_style_position_t list_style_position;
    ST_PUT_ENUM(border_style_top);
    ST_PUT_ENUM(border_style_right);
    ST_PUT_ENUM(border_style_bottom);
    ST_PUT_ENUM(border_style_left);
    ST_PUT_LEN4(border_width);
    ST_PUT_LEN4(border_color);
    buf<<background_image;
    ST_PUT_ENUM(background_repeat);
    ST_PUT_ENUM(background_position);
    ST_PUT_LEN(background_size[0]);
    ST_PUT_LEN(background_size[1]);
    ST_PUT_ENUM(border_collapse);
    ST_PUT_LEN(border_spacing[0]);
    ST_PUT_LEN(border_spacing[1]);
    ST_PUT_ENUM(orphans);
    ST_PUT_ENUM(widows);
    ST_PUT_ENUM(float_);
    ST_PUT_ENUM(clear);
    ST_PUT_ENUM(direction);
    ST_PUT_ENUM(visibility);
    ST_PUT_ENUM(line_break);
    ST_PUT_ENUM(word_break);
    ST_PUT_ENUM(box_sizing);
    buf << content;
    ST_PUT_LEN(cr_hint);
    lUInt32 hash = calcHash(*this);
    buf << hash;
    return !buf.error();
}

bool css_style_rec_t::deserialize( SerialBuf & buf )
{
    if ( buf.error() )
        return false;
    buf.putMagic(style_magic);
    buf >> important[0];                                    //    lUInt32              important[0];
    buf >> important[1];                                    //    lUInt32              important[1];
    buf >> important[2];                                    //    lUInt32              important[2];
    buf >> importance[0];                                   //    lUInt32              importance[0];
    buf >> importance[1];                                   //    lUInt32              importance[1];
    buf >> importance[2];                                   //    lUInt32              importance[2];
    ST_GET_ENUM(css_display_t, display);                    //    css_display_t        display;
    ST_GET_ENUM(css_white_space_t, white_space);            //    css_white_space_t    white_space;
    ST_GET_ENUM(css_text_align_t, text_align);              //    css_text_align_t     text_align;
    ST_GET_ENUM(css_text_align_t, text_align_last);         //    css_text_align_t     text_align_last;
    ST_GET_ENUM(css_text_decoration_t, text_decoration);    //    css_text_decoration_t text_decoration;
    ST_GET_ENUM(css_text_transform_t, text_transform);      //    css_text_transform_t text_transform;
    ST_GET_LEN(vertical_align);                             //    css_length_t         vertical_align;
    ST_GET_ENUM(css_font_family_t, font_family);            //    css_font_family_t    font_family;
    buf >> font_name;                                       //    lString8             font_name;
    ST_GET_LEN(font_size);                                  //    css_length_t         font_size;
    ST_GET_ENUM(css_font_style_t, font_style);              //    css_font_style_t     font_style;
    ST_GET_ENUM(css_font_weight_t, font_weight);            //    css_font_weight_t    font_weight;
    ST_GET_LEN(font_features);                              //    css_length_t         font_features;
    ST_GET_LEN(text_indent);                                //    css_length_t         text_indent;
    ST_GET_LEN(line_height);                                //    css_length_t         line_height;
    ST_GET_LEN(width);                                      //    css_length_t         width;
    ST_GET_LEN(height);                                     //    css_length_t         height;
    ST_GET_LEN(min_width);                                  //    css_length_t         min_width;
    ST_GET_LEN(min_height);                                 //    css_length_t         min_height;
    ST_GET_LEN(max_width);                                  //    css_length_t         max_width;
    ST_GET_LEN(max_height);                                 //    css_length_t         max_height;
    ST_GET_LEN4(margin);                                    //    css_length_t         margin[4]; ///< margin-left, -right, -top, -bottom
    ST_GET_LEN4(padding);                                   //    css_length_t         padding[4]; ///< padding-left, -right, -top, -bottom
    ST_GET_LEN(color);                                      //    css_length_t         color;
    ST_GET_LEN(background_color);                           //    css_length_t         background_color;
    ST_GET_LEN(letter_spacing);                             //    css_length_t         letter_spacing;
    ST_GET_ENUM(css_page_break_t, page_break_before);       //    css_page_break_t     page_break_before;
    ST_GET_ENUM(css_page_break_t, page_break_after);        //    css_page_break_t     page_break_after;
    ST_GET_ENUM(css_page_break_t, page_break_inside);       //    css_page_break_t     page_break_inside;
    ST_GET_ENUM(css_hyphenate_t, hyphenate);                //    css_hyphenate_t        hyphenate;
    ST_GET_ENUM(css_list_style_type_t, list_style_type);    //    css_list_style_type_t list_style_type;
    ST_GET_ENUM(css_list_style_position_t, list_style_position);//    css_list_style_position_t list_style_position;
    ST_GET_ENUM(css_border_style_type_t ,border_style_top);
    ST_GET_ENUM(css_border_style_type_t ,border_style_right);
    ST_GET_ENUM(css_border_style_type_t ,border_style_bottom);
    ST_GET_ENUM(css_border_style_type_t ,border_style_left);
    ST_GET_LEN4(border_width);
    ST_GET_LEN4(border_color);
    buf>>background_image;
    ST_GET_ENUM(css_background_repeat_value_t ,background_repeat);
    ST_GET_ENUM(css_background_position_value_t ,background_position);
    ST_GET_LEN(background_size[0]);
    ST_GET_LEN(background_size[1]);
    ST_GET_ENUM(css_border_collapse_value_t ,border_collapse);
    ST_GET_LEN(border_spacing[0]);
    ST_GET_LEN(border_spacing[1]);
    ST_GET_ENUM(css_orphans_widows_value_t, orphans);
    ST_GET_ENUM(css_orphans_widows_value_t, widows);
    ST_GET_ENUM(css_float_t, float_);
    ST_GET_ENUM(css_clear_t, clear);
    ST_GET_ENUM(css_direction_t, direction);
    ST_GET_ENUM(css_visibility_t, visibility);
    ST_GET_ENUM(css_line_break_t, line_break);
    ST_GET_ENUM(css_word_break_t, word_break);
    ST_GET_ENUM(css_box_sizing_t, box_sizing);
    buf>>content;
    ST_GET_LEN(cr_hint);
    lUInt32 hash = 0;
    buf >> hash;
    // printf("imp: %llx oldhash: %lx ", important, hash);
    lUInt32 newhash = calcHash(*this);
    // printf("newhash: %lx\n", newhash);
    if ( hash!=newhash )
        buf.seterror();
    return !buf.error();
}
