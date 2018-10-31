using System;
using System.Collections.Generic;

namespace room.server.data.Models
{
    public partial class RenderingType
    {
        public RenderingType()
        {
            Rendering = new HashSet<Rendering>();
        }

        public int Id { get; set; }
        public string Name { get; set; }
        public string Handler { get; set; }

        public ICollection<Rendering> Rendering { get; set; }
    }
}
