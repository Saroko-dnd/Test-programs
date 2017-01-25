using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using Microsoft.Xna.Framework.Graphics;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstTry.GameObjects
{
    public class AlgorithmDecimalToBinary : DrawableGameComponent
    {
        ContentManager _content;
        Rectangle _rectangleForDrawing;

        string _fontName;
        string _textureNameForTextBoxes;
        string _textureNameForButtons;

        Texture2D _textureForTextBoxes;
        Texture2D _textureForButtons;
        SpriteFont _font;


        public AlgorithmDecimalToBinary(Game1 game, ContentManager contentManager, Rectangle rectangleForDrawing, string fontName, string textureNameForTextBoxes, string textureNameForButtons) : base(game)
        {
            _rectangleForDrawing = rectangleForDrawing;
            _content = contentManager;
            _fontName = fontName;
            _textureNameForTextBoxes = textureNameForTextBoxes;
            _textureNameForButtons = textureNameForButtons;
        }

        protected override void LoadContent()
        {
            _textureForTextBoxes = _content.Load<Texture2D>(_textureNameForTextBoxes);
            _textureForButtons = _content.Load<Texture2D>(_textureNameForButtons);
            _font = _content.Load<SpriteFont>(_fontName);

            base.LoadContent();
        }
    }
}
