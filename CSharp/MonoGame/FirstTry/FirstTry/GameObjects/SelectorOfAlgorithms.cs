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
        List<Button> ListOfAlgorithms = new List<Button>();
        ContentManager Content;

        public SelectorOfAlgorithms(Game1 game)
            : base(game)
        {
            Content = new ContentManager(game.Services);
        }
    }
}
