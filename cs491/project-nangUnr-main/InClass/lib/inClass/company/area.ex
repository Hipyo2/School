defmodule InClass.Company.Area do
  use Ecto.Schema
  import Ecto.Changeset
  alias InClass.Company.Developer

  schema "areas" do
    field :name, :string
    has_many(:developers, Developer)
    timestamps()
  end

  @doc false
  def changeset(area, attrs) do
    area
    |> cast(attrs, [:name])
    |> validate_required([:name])
  end
end
