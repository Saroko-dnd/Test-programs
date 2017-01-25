using FirstTry.Controls;
using Microsoft.Xna.Framework;
using Microsoft.Xna.Framework.Content;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstTry.GameObjects
{
    public class SelectorOfAlgorithms : DrawableGameComponent
    {
        public enum Algorithms { DecimalToBinary, Second, Third };
        List<Button> _listOfAlgorithms = new List<Button>();
        ContentManager _content;

        string _fontNameForButtons;
        string _textureNameForButtons;
        Rectangle _sizeOfButtons;

        public SelectorOfAlgorithms(Game1 game, string fontNameForButtons, string textureNameForButtons, Rectangle sizeOfButtons)
            : base(game)
        {
            _content = new ContentManager(game.Services, "Content");
            _fontNameForButtons = fontNameForButtons;
            _textureNameForButtons = textureNameForButtons;
            _sizeOfButtons = sizeOfButtons;
        }

        ~SelectorOfAlgorithms()
        {
            UnloadContent();
        }

        public override void Initialize()
        {
            _listOfAlgorithms.Add(new Button((Game1)Game, _content, _textureNameForButtons, new Rectangle(2, 134, 202, 50), new Rectangle(2, 6, 202, 50), new Rectangle(2, 70, 202, 50), _sizeOfButtons, 
                0.9f, _fontNameForButtons)
            { Text = "Decimal to Binary" });

            foreach (Button FoundButton in _listOfAlgorithms)
            {
                FoundButton.Initialize();
            }

            base.Initialize();
        }

        protected override void LoadContent()
        {
            
            base.LoadContent();
        }

        public override void Update(GameTime gameTime)
        {
            foreach (Button FoundButton in _listOfAlgorithms)
            {
                FoundButton.Update(gameTime);
            }

            base.Update(gameTime);
        }

        public override void Draw(GameTime gameTime)
        {
            foreach (Button FoundButton in _listOfAlgorithms)
            {
                FoundButton.Draw(gameTime);
            }

            base.Draw(gameTime);
        }

        protected override void UnloadContent()
        {
            _content.Unload();
            base.UnloadContent();
        }

        public new void Dispose()
        {
            UnloadContent();
            base.Dispose();
        }
    }
}
