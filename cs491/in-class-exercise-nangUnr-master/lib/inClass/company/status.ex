defmodule InClass.Company.Status do
  use Ecto.Schema
  import Ecto.Changeset
  alias InClass.Company.Assignment

  schema "statuses" do
    field :name, :string
    has_many(:assignments, Assignment)
    timestamps()
  end

  @doc false
  def changeset(status, attrs) do
    status
    |> cast(attrs, [:name])
    |> validate_required([:name])
  end
end
